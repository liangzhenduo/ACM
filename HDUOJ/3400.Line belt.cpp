#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps=1e-7;
double p,q,r;
struct Point{
    double x,y;
};
double dis(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double find2(Point a,Point c,Point d){
    Point left,right,mid,midmid;
    double t1,t2;
    left=c,right=d;
    do{
        mid.x=(left.x+right.x)/2;
        mid.y=(left.y+right.y)/2;
        midmid.x=(mid.x+right.x)/2;
        midmid.y=(mid.y+right.y)/2;
        t1=dis(a,mid)/r+dis(mid,d)/q;
        t2=dis(a,midmid)/r+dis(midmid,d)/q;
        if(t1>t2)left=mid;
        else right=midmid;
    }while(dis(left,right)>=eps);
    return t1;
}
double find1(Point a,Point b,Point c,Point d){
    Point left,right,mid,midmid;
    double t1,t2;
    left=a,right=b;
    do{
        mid.x=(left.x+right.x)/2;
        mid.y=(left.y+right.y)/2;
        midmid.x=(mid.x+right.x)/2;
        midmid.y=(mid.y+right.y)/2;
        t1=dis(a,mid)/p+find2(mid,c,d);
        t2=dis(a,midmid)/p+find2(midmid,c,d);
        if(t1>t2)left=mid;
        else right=midmid;
    }while(dis(right,left)>=eps);
    return t1;
}
int main(){
    int t;
    Point a,b,c,d;
    scanf("%d",&t);
    while(t--){
        scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
        scanf("%lf%lf%lf%lf",&c.x,&c.y,&d.x,&d.y);
        scanf("%lf%lf%lf",&p,&q,&r);
        printf("%.2lf\n",find1(a,b,c,d));
    }
}
