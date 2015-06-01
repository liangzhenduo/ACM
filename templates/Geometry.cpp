#include <iostream>
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
double standard(double k){//防止反三角函数超过定义域
    if(k>1)k=1;
    if(k<-1)k=-1;
    return k;
}
double radian2degree(const double radian){//弧度转角度
    return radian/PI*180;
}
double degree2radian(const double degree){//角度转弧度
    return degree/180*PI;
}
int signum(const double x){//判断是否为0
    if(x<-EPS)return -1;
    if(x>EPS)return 1;
    return 0;
}
double regular(double theta){//将一个角变到[0,2*pi)
    while(theta<-PI)theta+=2*PI;
    while(theta>PI)theta-=2*PI;
    return theta;
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

class Line{//直线
public:
    double theta, l;
    Point p[2];
    Line() {}
    Line(const Point&a, const Point&b){
        theta = regular(atan2(a.x[1]-b.x[1], a.x[0]-b.x[0])+PI/2);
        l = Point::unit(theta)^(ORIGIN, a);
        p[0]=a;
        p[1]=b;
        //if(a.to(b)<EPS)throw(EXCEPTION_NOT_A_LINE);
    }
    Point operator*(const Line&b)const{//直线相交
        Point p;
        if(this->isParallel(b))throw(EXCEPTION_LINE_PARALLEL);
        p.x[0]=(l*sin(b.theta)-b.l*sin(theta))/sin(b.theta-theta);
        p.x[1]=(l*cos(b.theta)-b.l*cos(theta))/sin(theta-b.theta);
        return p;
    }
    int isParallel(const Line&b)const{//判断平行
        if(fabs((p[0],p[1])*(b.p[0],b.p[1]))>EPS)return 0;//不平行
        if(fabs((b.p[0],p[0])*(b.p[0],b.p[1]))>EPS)return 1;//平行不共线
        return 2;//共线
    }
    bool isVertical(const Line&l)const{//判断垂直
        return fabs((p[0],p[1])^(l.p[0],l.p[1]))<EPS;
    }
    static bool compareByTheta(const Line&a,const Line&b){//比较直线斜率
        if(signum(a.theta-b.theta)==0)
            return a.l>b.l;
        return a.theta<b.theta;
    }
    bool in(const Point&pt)const{//判断点是否在直线上
        if(fabs((pt-p[0])*(pt-p[1]))>EPS)return false;
        return true;
    }
    Point Projection(const Point&pt)const{//点在直线上的投影
        if(in(pt))return pt;
        if(fabs((pt-p[0])^(p[1]-p[0]))<EPS)return p[0];
        double tmp=((pt-p[0])^(p[1]-p[0]).unit());
        return (p[1]-p[0]).unit()*tmp
        +p[0];
    }
    double to(const Point&pt)const{//点到直线距离
        Point proj=Projection(pt);
        return pt.to(proj);
    }
};

class Segment:public Line{//线段
public:
    Segment(){}
    Segment(const Point&a, const Point&b){
        theta = regular(atan2(a.x[1]-b.x[1], a.x[0]-b.x[0])+PI/2);
        l = Point::unit(theta)^(ORIGIN, a);
        p[0]=a;
        p[1]=b;
        //if(a.to(b)<EPS)throw(EXCEPTION_NOT_A_LINE);
    }
    bool in(const Point&pt)const{//判断点是否在线段上
        if(fabs((pt-p[0])*(pt-p[1]))>EPS)return false;
        if(pt<p[0]&&pt<p[1])return false;
        if(p[0]<pt&&p[1]<pt)return false;
        return true;
    }
    Line perpendicularBisector()const{//中垂线
        Point mid=(p[0]+p[1])/2;
        Point vec=(p[1]-p[0]).verticalVector();
        return Line(mid,mid+vec);
    }
    Point operator*(const Segment&b)const{//线段相交
        Point p;
        if(this->isParallel(b))throw(EXCEPTION_LINE_PARALLEL);
        p.x[0]=(l*sin(b.theta)-b.l*sin(theta))/sin(b.theta-theta);
        p.x[1]=(l*cos(b.theta)-b.l*cos(theta))/sin(theta-b.theta);
        if(!this->in(p))throw(EXCEPTION_POINT_OUT_OF_LINE);
        if(b.in(p))throw(EXCEPTION_POINT_OUT_OF_LINE);
        return p;
    }
    Point operator*(const Line&b)const{//线段与直线相交
        Point p;
        if(this->isParallel(b))throw(EXCEPTION_LINE_PARALLEL);
        p.x[0]=(l*sin(b.theta)-b.l*sin(theta))/sin(b.theta-theta);
        p.x[1]=(l*cos(b.theta)-b.l*cos(theta))/sin(theta-b.theta);
        if(!this->in(p))throw(EXCEPTION_POINT_OUT_OF_LINE);
        return p;
    }
    bool Intersect(const Segment&o)const{//判断两线段是否相交
        try{
            *this*o;
        }catch(GEOMETRY_ERROR e){
            return false;
        }
        return true;
    }
    bool Intersect(const Line&o)const{//判断线段与直线是否相交
        try{
            *this*o;
        }catch(GEOMETRY_ERROR e){
            return false;
        }
        return true;
    }
    double to(const Point&pt)const{//点到线段距离
        Point proj=Projection(pt);
        if(in(proj))return pt.to(proj);
        return min(pt.to(p[0]),pt.to(p[1]));
    }
};

class Angle{//角
public:
    Angle(){}
    vector<Point>p;
    Angle(const Point&a,const Point&b,const Point&c){//a是顶点
        p.push_back(a);
        p.push_back(b);
        p.push_back(c);
    }
    Line angularBisector()const{//角平分线
        Point p1=(p[0],p[1]).unit();
        Point p2=(p[0],p[2]).unit();
        Point tmp=Segment(p[0],p[0]+p1).perpendicularBisector()*Segment(p[0],p[0]+p2).perpendicularBisector();
        return Line(p[0],tmp);
    }
    double size()const{//角的大小
        double l1=p[0].to(p[1]);
        double l2=p[0].to(p[2]);
        return acos(standard(((p[0],p[1])^(p[0],p[2]))/l1/l2));
    }
};

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
    Point FermatPoint()const{//费马点,随机淬火
        double stp=INF;
        Point tmp(0,0);
        while(stp>EPS){
            Point delta(0,0);
            double dx=0,dy=0;
            for(int i=0;i<n;i++){
                if(tmp.to(p[i])>EPS){
                    delta=delta+(p[i],tmp)/tmp.to(p[i]);
                }
            }
            if(delta.len()<EPS)break;
            tmp=tmp-delta.unit()*stp;
            stp*=0.8;//摩擦系数,自己设定,会影响到结果和运行时间
        }
        return tmp;
    }
    double fermatDis()const{
        Point center=FermatPoint();
        double ans=0;
        for(int i=0;i<n;i++)
            ans+=p[i].to(center);
        return ans;
    }
};

class Circle{//圆
public:
    Point center;
    double radius;
    Circle(){}
    Circle(const Point&c,double r){
        center=c;
        radius=r;
        //if(r<EPS)throw(EXCEPTION_NOT_A_CIRCLE);
    }
    Circle(double r){
        center=ORIGIN;
        radius=r;
        //if(r<EPS)throw(EXCEPTION_NOT_A_CIRCLE);
    }
    double area()const{
        return PI*radius*radius;
    }
    int posToCircle(const Line&l)const{//直线和圆的位置关系,交点个数
        double dis=l.to(center);
        if(dis<radius-EPS)return 2;//相交
        if(dis>radius+EPS)return 0;//相离
        return 1;//相切
    }
    int posToCircle(const Point&p)const{//点和圆的位置关系
        double dis=(center,p).len();
        if(dis<radius-EPS)return -1;//圆内
        if(dis>radius+EPS)return 1;//圆外
        return 0;//圆上
    }
    int posToCircle(const Circle&c)const{//圆和圆的位置关系
        double dis=(center,c.center).len();
        if(dis<fabs(radius-c.radius)-EPS)return -1;//内含
        if(dis>radius+c.radius+EPS)return -2;//相离
        if(dis>fabs(radius-c.radius)-EPS&&dis<fabs(radius-c.radius)+EPS)return 1;//内切
        if(dis>fabs(radius+c.radius)-EPS&&dis<fabs(radius+c.radius)+EPS)return 2;//外切
        return 0;//相交
    }
    double circumference()const{//周长
        return PI*2*radius;
    }
    vector<Point> operator*(const Line&l)const{//直线与圆的交点
        int tmp=posToCircle(l);
        vector<Point>res;
        if(tmp==0)return res;
        Point pt=l.Projection(center);
        if(tmp==1){
            res.push_back(pt);
            return res;
        }
        double dd=sqrt(square(radius)-square(pt.to(center)));
        Point pp=(l.p[0],l.p[1]).unit()*dd;
        res.push_back(pt-pp);
        res.push_back(pt+pp);
        if(res.size()==2&&res[0].to(res[1])<EPS){
            Point ptmp=(res[0]+res[1])/2;
            res.clear();
            res.push_back(ptmp);
        }
        return res;
    }
    vector<Point> operator*(const Segment&l)const{//线段与圆的交点
        vector<Point>tmp=*this*(Line(l.p[0],l.p[1]));
        vector<Point>res;
        for(int i=0;i<tmp.size();i++)
            if(l.in(tmp[i]))res.push_back(tmp[i]);
        if(res.size()==2&&res[0].to(res[1])<EPS){
            Point ptmp=(res[0]+res[1])/2;
            res.clear();
            res.push_back(ptmp);
        }
        return res;
    }
    vector<Point> operator*(const Circle&o)const{//圆与圆的交点
        int tmp=posToCircle(o);
        vector<Point>res;
        if(tmp<0)return res;
        else if(tmp==2){
            Point vec=(center,o.center);
            vec=vec*radius/(radius+o.radius);
            res.push_back(center+vec);
            return res;
        }
        else if(tmp==1){
            Point vec=(center,o.center);
            vec=vec*radius/(radius-o.radius);
            res.push_back(center+vec);
            return res;
        }
        return *this*Segment(center,o.center).perpendicularBisector();
    }
};

class Triangle:public PointSet{//三角形
public:
    Triangle(){}
    Triangle(const Point&a,const Point&b,const Point&c){
        n=3;
        p.push_back(a);
        p.push_back(b);
        p.push_back(c);
    }
    double area()const{//面积
        return fabs((p[1]-p[0])*(p[2]-p[0]))/2;
    }
    int type()const{//判断三角形类型
        double tmp=INF;
        tmp=min(tmp,(p[0],p[1]).unit()^(p[0],p[2]).unit());
        tmp=min(tmp,(p[1],p[0]).unit()^(p[1],p[2]).unit());
        tmp=min(tmp,(p[2],p[1]).unit()^(p[2],p[0]).unit());
        if(tmp>EPS)return 1;//锐角
        if(tmp<-EPS)return -1;//钝角
        return 0;//直角
    }
    Point centroid()const{//重心
        return (p[0]+p[1]+p[2])/3;
    }
    Point circumcentre()const{//外心
        Line l1=Segment(p[0],p[1]).perpendicularBisector();
        Line l2=Segment(p[2],p[1]).perpendicularBisector();
        return l1*l2;
    }
    Point orthocentre()const{//垂心
        Line l1=Line(p[0],Line(p[1],p[2]).Projection(p[0]));
        Line l2=Line(p[1],Line(p[0],p[2]).Projection(p[1]));
        return l1*l2;
    }
    Point incentre()const{//内心
        Line l1=Angle(p[0],p[1],p[2]).angularBisector();
        Line l2=Angle(p[1],p[2],p[0]).angularBisector();
        return l1*l2;
    }
    Point FermatPoint()const{//费马点
        if((p[0],p[1])*(p[0],p[2])<0)return Triangle(p[0],p[2],p[1]).FermatPoint();
        Point mid1=(p[0]+p[1])/2;
        Point dd1=(p[1]-p[0]).verticalVector()*sqrt(3.0)/2;
        Line l1=Line(p[2],mid1-dd1);
        Point mid2=(p[0]+p[2])/2;
        Point dd2=(p[2]-p[0]).verticalVector()*sqrt(3.0)/2;
        Line l2=Line(p[1],mid2+dd2);
        return l1*l2;
    }
    Circle circumcircle()const{//外接圆
        Point center=circumcentre();
        return Circle(center,center.to(p[0]));
    }
    Circle incircle()const{//内切圆
        Point center=incentre();
        return Circle(center,Line(p[0],p[1]).to(center));
    }
    bool in(const Point&pt){//判断一个点是否在三角形内
        if((p[0],p[1])*(p[0],p[2])<-EPS)swap(p[2],p[1]);
        for(int i=0;i<3;i++){
            if((pt,p[i])*(pt,p[(i+1)%3])<-EPS)return false;
        }
        return true;
    }
};

class Sephirot{//质点
public:
    double weight;
    Point p;
    Sephirot(){}
    Sephirot(Point a,Point b,Point c){
        p=(a+b+c)/3;
        weight=(a,b)*(a,c);
    }
    Sephirot operator+(const Sephirot&o)const{//合并
        if(fabs(o.weight)<EPS)return *this;
        Sephirot tmp;
        tmp.weight=weight+o.weight;
        tmp.p=p+(p,o.p)/tmp.weight*o.weight;
        return tmp;
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
    double to(const Point&pt)const{//点到多边形距离
        double tmp=INF;
        for(int i=0;i<n;i++){
            tmp=min(tmp,Segment(p[i],p[(i+1)%n]).to(pt));
        }
        return tmp;
    }
    double circumference()const{//周长
        double tmp=0;
        for(int i=0;i<n;i++)
            tmp+=p[i].to(p[(i+1)%n]);
        return tmp;
    }
    bool Convex()const{//判断是否是凸多边形
        for(int i=0;i<n;i++){
            Point a=p[i],b=p[(i+1)%n],c=p[(i+2)%n];
            if(((a,b)*(b,c))<-EPS)return false;
        }
        return true;
    }
    bool Intersect()const{//判断多边形是否自交
        for(int i=0;i<n;i++){
            for(int j=i+2;j<n;j++){
                if((j+1)%n==i)continue;
                if(Segment(p[i],p[(i+1)%n]).Intersect(Segment(p[j],p[(j+1)%n])))return true;
            }
        }
        return false;
    }
    bool in(const Point&pt)const{//判断点是否在多边形内
        for(int i=0;i<n;i++){
            if((pt,p[i])*(pt,p[(i+1)%n])<-EPS)return false;
        }
        return true;
    }
    Polygon Revert()const{//顺时针,逆时针互换
        Polygon tmp;
        for(int i=n-1;i>=0;i--)
            tmp.add(p[i]);
        return tmp;
    }
    Sephirot centerOfMass()const{//重心,质心
        vector<Sephirot> tmp;
        Point pt(0,0);//随便选一个,可能会产生精度问题
        for(int i=0;i<n;i++){
            tmp.push_back(Sephirot(pt,p[i],p[(i+1)%n]));
        }
        while(tmp.size()>1){
            vector<Sephirot> _tmp;
            for(int i=0;i<tmp.size();i+=2){
                if(i==tmp.size()-1)_tmp.push_back(tmp[i]);
                else _tmp.push_back(tmp[i]+tmp[i+1]);
            }
            tmp=_tmp;
        }
        return tmp[0];
    }
};

class minDisPair:public PointSet{//最近点对O(n*log(n))
    minDisPair(minDisPair*base,const int fr,const int to){
        for(int i=fr;i<to;i++)
            p.push_back(base->p[i]);
        n=to-fr;
    }
    minDisPair close(const double X,const double ds)const{
        minDisPair tmp;
        for(int i=0;i<n;i++)
            if(fabs(p[i].x[0]-X)<ds+EPS)
                tmp.add(p[i]);
        return tmp;
    }
public:
    minDisPair(){}
    double solve(){//计算
        if(n==1){
            return INF;
        }
        if(n<=3){
            double tmp=INF;
            for(int i=0;i<n;i++)
                for(int j=i+1;j<n;j++)
                    tmp=min(tmp,p[i].to(p[j]));
            return tmp;
        }
        sort(p.begin(),p.end(),Point::cmpByX);
        minDisPair left(this,0,n/2);
        minDisPair right(this,n/2,n);
        double tmp=min(left.solve(),right.solve());
        minDisPair ll=left.close(p[n/2].x[0],tmp);
        minDisPair rr=right.close(p[n/2].x[0],tmp);
        sort(ll.p.begin(),ll.p.end(),Point::cmpByY);
        sort(rr.p.begin(),rr.p.end(),Point::cmpByY);
        double _tmp=INF;
        int pre=0;
        for(int i=0;i<ll.n;i++){
            int nxt=rr.n;
            for(int j=pre;j<rr.n;j++){
                if(rr.p[j].x[1]>ll.p[i].x[1]+tmp+EPS){
                    nxt=min(nxt,j);
                    break;
                }
                if(i<ll.n-1&&rr.p[j].x[1]>ll.p[i+1].x[1]-tmp-EPS)nxt=min(nxt,j);
                _tmp=min(_tmp,ll.p[i].to(rr.p[j]));
            }
            pre=nxt;
        }
        return min(_tmp,tmp);
    }
};

class ConvexHull:public PointSet{//凸包O(n*log(n))
    static Point O;
    deque<Point>que;
    static bool cmpByAngle(const Point&a,const Point&b){
        double tmp=(O,a)*(O,b);
        if(fabs(tmp)<EPS){
            return O.to(a)<O.to(b);
        }
        return tmp>0;
    }
    Point rearGet(const int ind){
        deque<Point>::iterator itr=que.end();
        for(int i=0;i<=ind;i++)itr--;
        return *itr;
    }
public:
    Polygon solve(){//计算
        if(n==0)return Polygon();
        O=p[0];
        for(int i=1;i<n;i++){
            if(p[i].x[0]<O.x[0]-EPS||(fabs(p[i].x[0]-O.x[0])<EPS&&p[i].x[1]<O.x[1]-EPS))
                O=p[i];
        }
        sort(p.begin(),p.end(),ConvexHull::cmpByAngle);
        que.clear();
        que.push_back(p[0]);
        for(int i=1;i<n;i++){
            while(que.size()>1){
                Point p1=rearGet(1);
                Point p2=rearGet(0);
                if((p1,p2)*(p2,p[i])>EPS)break;
                que.pop_back();
            }
            que.push_back(p[i]);
        }
        Polygon res;
        while(!que.empty()){
            res.add(que.front());
            que.pop_front();
        }
        return res;
    }
};
Point ConvexHull::O;

class maxDisPair:public ConvexHull{//最远点对
public:
    double _solve(){//计算,注意函数名,和base的solve区分,因为要用到base的solve,所以不能重载掉
        double tmp=0;
        Polygon rs=solve();
        int j=1;
        for(int i=0;i<rs.n;i++){
            j=min(j,i+1);
            while(j<rs.n){
                if(rs.p[i].to(rs.p[j])<rs.p[i].to(rs.p[j-1]))break;
                tmp=max(tmp,rs.p[i].to(rs.p[j]));
                j++;
            }
            j--;
        }
        return tmp;
    }
};

class halfPlane{//半平面交O(n*log(n))
    bool outOfHalfPlane(const Point&p,const Line&line)const{
        return signum(((ORIGIN, p)^Point::unit(line.theta))-line.l)>0;
    }
    Line rearGet(const int ind){
        deque<Line>::iterator itr=result.end();
        for(int i=0;i<=ind;i++)itr--;
        return *itr;
    }
    Line frontGet(const int ind){
        deque<Line>::iterator itr=result.begin();
        for(int i=0;i<ind;i++)itr++;
        return *itr;
    }
public:
    vector<Line>lines;
    deque<Line>result;
    int n;
    halfPlane(){
        clear();
    }
    void clear(){//清空
        lines.clear();
        result.clear();
        n=0;
    }
    void add(const Line&l){//加入半平面
        n++;
        lines.push_back(l);
    }
    Polygon convert(){//将结果转化为一个多边形
        Polygon tmp;
        deque<Line>::iterator itr1=result.begin();
        deque<Line>::iterator itr2=itr1;
        itr2++;
        while(itr2!=result.end()){
            Line l1=*itr1;
            Line l2=*itr2;
            tmp.add(l1*l2);
            itr1++;
            itr2++;
        }
        tmp.add(result.back()*result.front());
        return tmp;
    }
    void goon(){//将结果作为新的集合
        lines.clear();
        n=0;
        while(!result.empty()){
            lines.push_back(result.front());
            n++;
            result.pop_front();
        }
    }
    int solve(){//计算
        result.clear();
        sort(lines.begin(),lines.end(),Line::compareByTheta);
        for(int i=0;i<n;i++){
            if(i+1<n&&signum(lines[i].theta-lines[i+1].theta)==0)continue;
            bool flag=false;
            while(result.size()>1){
                Point p=rearGet(0)*rearGet(1);
                if(outOfHalfPlane(p,lines[i])){
                    if(rearGet(1).isParallel(lines[i])){
                        if(signum(rearGet(1).l+lines[i].l)<0){
                            result.clear();
                            return 0;
                        }
                        if(signum(rearGet(1).l+lines[i].l)==0){
                            result.push_back(lines[i]);
                            flag=true;
                            break;
                        }
                    }
                    else if(outOfHalfPlane(lines[i]*rearGet(1), rearGet(0))){
                        Point pp=lines[i]*rearGet(1);
                        result.clear();
                        return 0;
                    }
                    result.pop_back();
                }
                else break;
            }
            if(flag)continue;
            while(result.size()>1){
                Point p=frontGet(0)*frontGet(1);
                if(outOfHalfPlane(p,lines[i])){
                    if(frontGet(1).isParallel(lines[i])){
                        if(signum(frontGet(1).l+lines[i].l)<0){
                            result.clear();
                            return 0;
                        }
                        if(signum(frontGet(1).l+lines[i].l)==0){
                            result.push_back(lines[i]);
                            flag=true;
                            break;
                        }
                    }
                    else if(outOfHalfPlane(lines[i]*frontGet(1),frontGet(0))){
                        Point pp=lines[i]*frontGet(1);
                        result.clear();
                        return 0;
                    }
                    result.pop_front();
                }
                else break;
            }
            if(flag)continue;
            if(!result.empty()&&outOfHalfPlane(rearGet(0)*lines[i],frontGet(0)))continue;
            result.push_back(lines[i]);
        }
        return result.size();
    }
};

class minimumEnvelopeCircle:public PointSet{//最小包围圆,随机增量,期望O(n)
    Circle twoPoint(const Point&a,const Point&b)const{
        return Circle((a+b)/2,a.to(b)/2);
    }
    Circle coverPoints(const int j,const int k)const{
        Circle tmp=twoPoint(p[j],p[k]);
        for(int i=0;i<j;i++){
            if(tmp.posToCircle(p[i])==1)tmp=Triangle(p[i],p[j],p[k]).circumcircle();
        }
        return tmp;
    }
    Circle coverPoint(const int k)const{
        Circle tmp=twoPoint(p[0],p[k]);
        for(int i=1;i<k;i++){
            if(tmp.posToCircle(p[i])==1)tmp=coverPoints(i,k);
        }
        return tmp;
    }
public:
    Circle solve(){//计算
        if(n==1){
            return Circle(p[0],0);
        }
        random_shuffle(p.begin(),p.end());
        Circle tmp=twoPoint(p[0],p[1]);
        for(int i=2;i<n;i++){
            if(tmp.posToCircle(p[i])==1)tmp=coverPoint(i);
        }
        return tmp;
    }
};

class Rotate{//旋转
public:
    Point rotate(const Point&o,const Point&c,const double theta)const{//点o绕c逆时针旋转theta,弧度
        Point vec=(c,o);
        double x=vec.x[0]*cos(theta)-vec.x[1]*sin(theta);
        double y=vec.x[0]*sin(theta)+vec.x[1]*cos(theta);
        return c+Point(x,y);
    }
    Line rotate(const Line&o,const Point&c,const double theta)const{//直线(线段)o绕c逆时针旋转theta,弧度
        return Line(rotate(o.p[0],c,theta),rotate(o.p[1],c,theta));
    }
    PointSet rotate(const PointSet&o,const Point&c,const double theta)const{//点集(多边形,三角形等等)o绕c逆时针旋转theta,弧度
        PointSet tmp;
        for(int i=0;i<o.n;i++)
            tmp.add(rotate(o.p[i],c,theta));
        return tmp;
    }
};

class Mirror{//镜像,关于一条直线(线段)的对称图像
public:
    Point mirror(const Point&o,const Line&l)const{//对称点
        Point proj=l.Projection(o);
        return proj*2-o;
    }
    Line mirror(const Line&o,const Line&l)const{//对称直线
        return Line(mirror(o.p[0],l),mirror(o.p[1],l));
    }
    PointSet mirror(const PointSet&o,const Line&l)const{//对称点集
        PointSet tmp;
        for(int i=0;i<o.n;i++)
            tmp.add(mirror(o.p[i],l));
        return tmp;
    }
};

class Triangulation:public Polygon{//三角剖分
public:
    Triangulation(){}
    vector<Triangle> solve(){//计算
        vector<Triangle> tmp;
        return tmp;
    }
};

class Sector{//扇形
public:
    Circle o;
    double theta;
    Sector(){}
    Sector(const Circle&oo,const double aa){
        o=oo;
        theta=aa;
    }
    Sector(const Circle&oo,const Point&a,const Point&b){//角aob为圆心角
        o=oo;
        theta=Angle(o.center,a,b).size();
    }
    double area()const{//扇形面积
        return square(o.radius)*theta/2;
    }
    double arcuate()const{//弓形面积
        return area()-square(o.radius)*sin(theta)/2;
    }
};

double operator*(Circle&o,Triangle&t){//圆和三角形的面积交
    if(t.area()<EPS||o.radius<EPS)return 0;
    if((t.p[0],t.p[1])*(t.p[0],t.p[2])<-EPS){
        swap(t.p[1],t.p[2]);
    }
    int cc=0;
    for(int i=0;i<3;i++){
        if(o.posToCircle(t.p[i])<=0)cc++;
    }//按几个点在园内分类讨论
    bool inside=t.in(o.center);
    if(cc==0){
        double tmp=o.area();
        bool flag=true;
        for(int i=0;i<3;i++){
            vector<Point> pts=o*Segment(t.p[i],t.p[(i+1)%3]);
            if(pts.size()==2){
                if((o.center,pts[0])*(o.center,pts[1])>0)tmp-=Sector(o,pts[0],pts[1]).arcuate();
                else tmp-=o.area()-Sector(o,pts[0],pts[1]).arcuate();
                flag=false;
            }
        }
        if(flag&&!inside)return 0;//相离
        return tmp;
    }
    else if(cc==1){
        if(o.posToCircle(t.p[1])<=0){
            swap(t.p[0],t.p[1]);
            swap(t.p[2],t.p[1]);
        }
        else if(o.posToCircle(t.p[2])<=0){
            swap(t.p[0],t.p[1]);
            swap(t.p[0],t.p[2]);
        }
        Segment l(t.p[1],t.p[2]);
        vector<Point> pts=o*l;
        vector<Point> vv1=o*(Segment(t.p[0],t.p[1]));
        Point a=vv1[0];
        if(vv1.size()==2&&a.to(t.p[0])<EPS)a=vv1[1];
        vector<Point> vv2=o*(Segment(t.p[0],t.p[2]));
        Point b=vv2[0];
        if(vv2.size()==2&&b.to(t.p[0])<EPS)b=vv2[1];
        double res=Triangle(t.p[0],a,b).area()+Sector(o,a,b).arcuate();
        if((o.center,a)*(o.center,b)<0)res=Triangle(t.p[0],a,b).area()+o.area()-Sector(o,a,b).arcuate();
        if(pts.size()==2){
            if((o.center,pts[0])*(o.center,pts[1])>0)res-=Sector(o,pts[0],pts[1]).arcuate();
            else res-=o.area()-Sector(o,pts[0],pts[1]).arcuate();
        }
        return res;
    }
    else if(cc==2){
        if(o.posToCircle(t.p[1])>0){
            swap(t.p[0],t.p[1]);
            swap(t.p[2],t.p[1]);
        }
        else if(o.posToCircle(t.p[2])>0){
            swap(t.p[0],t.p[1]);
            swap(t.p[0],t.p[2]);
        }
        vector<Point> vv1=o*(Segment(t.p[0],t.p[1]));
        Point a=vv1[0];
        if(vv1.size()==2&&a.to(t.p[1])<EPS)a=vv1[1];
        vector<Point> vv2=o*(Segment(t.p[0],t.p[2]));
        Point b=vv2[0];
        if(vv2.size()==2&&b.to(t.p[2])<EPS)b=vv2[1];
        if((o.center,b)*(o.center,a)>0)return Sector(o,a,b).arcuate()+Triangle(t.p[1],a,b).area()+Triangle(t.p[1],t.p[2],b).area();
        return o.area()-Sector(o,a,b).arcuate()+Triangle(t.p[1],a,b).area()+Triangle(t.p[1],t.p[2],b).area();
    }
    else{
        return t.area();
    }
}

int main(){

}
