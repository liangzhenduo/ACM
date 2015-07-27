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
double square(double k){//ƽ��
    return k*k;
}

enum GEOMETRY_ERROR{//�쳣
    EXCEPTION_ZERO_VECTOR = 1,
    EXCEPTION_LINE_PARALLEL = 2,
    EXCEPTION_POINT_OUT_OF_LINE = 3,
    EXCEPTION_NOT_A_LINE = 4,
    EXCEPTION_NOT_A_CIRCLE = 5,
    EXCEPTION_NOT_AN_ANGLE = 6
};

class Point{//��,����
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
    Point operator+(const Point&o)const{//�������
        Point tmp;
        tmp.x[0]=x[0]+o.x[0];
        tmp.x[1]=x[1]+o.x[1];
        return tmp;
    }
    double operator^(const Point&o)const{//���
        double ans=0.0;
        for(int i=0;i<2;++i)
            ans+=x[i]*o.x[i];
        return ans;
    }
    Point operator,(const Point&b)const{//*this->b������
        Point v;
        for(int i=0;i!=2;++i)
            v.x[i]=b.x[i]-x[i];
        return v;
    }
    Point operator-(const Point&o)const{//�������
        return o,*this;
    }
    static Point unit(const double theta){//��λ����
        Point v;
        v.x[0]=cos(theta);
        v.x[1]=sin(theta);
        return v;
    }
    double operator*(const Point&b)const{//���
        return x[0]*b.x[1]-x[1]*b.x[0];
    }
    Point operator*(const double k)const{//����
        Point tmp;
        tmp.x[0]=x[0]*k;
        tmp.x[1]=x[1]*k;
        return tmp;
    }
    Point operator/(const double k)const{//����
        Point tmp;
        tmp.x[0]=x[0]/k;
        tmp.x[1]=x[1]/k;
        return tmp;
    }
    bool operator<(const Point&b)const{//�Ƚ������ϵ,X��������
        return cmpByX(*this,b);
    }
    double len()const{//����ģ��
        return sqrt(square(x[0])+square(x[1]));
    }
    double to(const Point&o)const{//�������
        return (*this,o).len();
    }
    Point unit()const{//��λ������
        Point tmp=*this;
        if(this->len()>EPS){
            tmp.x[0]/=this->len();
            tmp.x[1]/=this->len();
        }
        else throw(EXCEPTION_ZERO_VECTOR);
        return tmp;
    }
    Point verticalVector()const{//������ʱ����ת90��
        Point tmp=*this;
        swap(tmp.x[0],tmp.x[1]);
        tmp.x[0]*=-1;
        return tmp;
    }
    static bool cmpByX(const Point&a,const Point&b){//�Ƚ������ϵ,X��������
        if(fabs(a.x[0]-b.x[0])<EPS)return a.x[1]<b.x[1];
        return a.x[0]<b.x[0];
    }
    static bool cmpByY(const Point&a,const Point&b){//�Ƚ������ϵ,Y��������
        if(fabs(a.x[1]-b.x[1])<EPS)return a.x[0]<b.x[0];
        return a.x[1]<b.x[1];
    }
}ORIGIN;

class PointSet{//��ļ���
public:
    int n;
    vector<Point>p;
    PointSet(){
        clear();
    }
    void add(const Point&pt){//�ӵ�
        n++;
        p.push_back(pt);
    }
    void add(double x,double y){//�ӵ�,�򵥵�д��
        add(Point(x,y));
    }
    void clear(){//���
        n=0;
        p.clear();
    }
};

class Polygon:public PointSet{//�����,˳ʱ��
public:
    double area()const{//���
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
