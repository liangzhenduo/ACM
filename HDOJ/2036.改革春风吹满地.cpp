#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <deque>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <iomanip>
using namespace std;
const double PI=acos(-1.0);
const double EPS=1e-9;
const double INF=1e9;
double square(double k){//平方
    return k*k;
}

enum GEOMETRY_ERROR{//异常
    EXCEPTION_ZERO_VECTOR = 1,
    EXCEPTION_LINE_PARALLEL = 2,
    EXCEPTION_POINT_OUT_OF_LINE = 3,
    EXCEPTION_NOT_A_LINE = 4,
    EXCEPTION_NOT_A_CIRCLE = 5,
    EXCEPTION_NOT_AN_ANGLE = 6
};

class Point{//点,向量
public:
    double x[2];
    Point(){
        x[0]=0.0;
        x[1]=0.0;
    }
    Point(const double _x,const double _y){
        x[0]=_x;
        x[1]=_y;
    }
    void out()const{
        printf("(%.5lf,%.5lf)\n",x[0],x[1]);
    }
    Point operator+(const Point&o)const{//向量相加
        Point tmp;
        tmp.x[0]=x[0]+o.x[0];
        tmp.x[1]=x[1]+o.x[1];
        return tmp;
    }
    double operator^(const Point&o)const{//点积
        double ans=0.0;
        for(int i=0;i<2;++i)
            ans+=x[i]*o.x[i];
        return ans;
    }
    Point operator,(const Point&b)const{//*this->b的向量
        Point v;
        for(int i=0;i!=2;++i)
            v.x[i]=b.x[i]-x[i];
        return v;
    }
    Point operator-(const Point&o)const{//向量相减
        return o,*this;
    }
    static Point unit(const double theta){//单位向量
        Point v;
        v.x[0]=cos(theta);
        v.x[1]=sin(theta);
        return v;
    }
    double operator*(const Point&b)const{//叉积
        return x[0]*b.x[1]-x[1]*b.x[0];
    }
    Point operator*(const double k)const{//数乘
        Point tmp;
        tmp.x[0]=x[0]*k;
        tmp.x[1]=x[1]*k;
        return tmp;
    }
    Point operator/(const double k)const{//数乘
        Point tmp;
        tmp.x[0]=x[0]/k;
        tmp.x[1]=x[1]/k;
        return tmp;
    }
    bool operator<(const Point&b)const{//比较坐标关系,X坐标优先
        return cmpByX(*this,b);
    }
    double len()const{//向量模长
        return sqrt(square(x[0])+square(x[1]));
    }
    double to(const Point&o)const{//两点距离
        return (*this,o).len();
    }
    Point unit()const{//单位化向量
        Point tmp=*this;
        if(this->len()>EPS){
            tmp.x[0]/=this->len();
            tmp.x[1]/=this->len();
        }
        else throw(EXCEPTION_ZERO_VECTOR);
        return tmp;
    }
    Point verticalVector()const{//向量逆时针旋转90度
        Point tmp=*this;
        swap(tmp.x[0],tmp.x[1]);
        tmp.x[0]*=-1;
        return tmp;
    }
    static bool cmpByX(const Point&a,const Point&b){//比较坐标关系,X坐标优先
        if(fabs(a.x[0]-b.x[0])<EPS)return a.x[1]<b.x[1];
        return a.x[0]<b.x[0];
    }
    static bool cmpByY(const Point&a,const Point&b){//比较坐标关系,Y坐标优先
        if(fabs(a.x[1]-b.x[1])<EPS)return a.x[0]<b.x[0];
        return a.x[1]<b.x[1];
    }
}ORIGIN;

class PointSet{//点的集合
public:
    int n;
    vector<Point>p;
    PointSet(){
        clear();
    }
    void add(const Point&pt){//加点
        n++;
        p.push_back(pt);
    }
    void add(double x,double y){//加点,简单的写法
        add(Point(x,y));
    }
    void clear(){//清空
        n=0;
        p.clear();
    }
};

class Polygon:public PointSet{//多边形,顺时针
public:
    double area()const{//面积
        double tmp=0;
        for(int i=0;i<n;i++){
            tmp+=p[i]*p[(i+1)%n];
        }
        return fabs(tmp/2);
    }
};

int main(){
    int n,i,j;
    double x,y;
    while(scanf("%d",&n)&&n){
        Polygon p;
        for(i=0;i<n;i++){
            scanf("%lf%lf",&x,&y);
            p.add(Point(x,y));
        }
        printf("%.1lf\n",p.area());
    }
}
