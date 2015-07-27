#include <cstdio>
#include <cmath>
#include <algorithm>
#define eps 1e-8
#define PI acos(-1)
using namespace std;
double ans;
int n;
struct Circle{
    double x,y,r;
}c[20];
double dis(int i,int j){
    return sqrt((c[i].x-c[j].x)*(c[i].x-c[j].x)+(c[i].y-c[j].y)*(c[i].y-c[j].y));
}
double fsf(double a,double c,double b){
    double ang=2*acos((a*a+b*b-c*c)/(2*a*b));
    return a*a*(ang-sin(ang))/2;
}
bool cmn(int i,double r,int j){
    double d=dis(i,j);
    if(d>=r+c[j].r) return 0;
    if(d<=fabs(r-c[j].r))
        if(r>c[j].r) return 1;
        else return r*r*2>=c[j].r*c[j].r;
    double v=fsf(r,c[j].r,d)+fsf(c[j].r,r,d);
    return 2*v>=c[j].r*c[j].r*PI;
}
double cal(int i){
    double l=0,r=12000,mid;
    int j;
    while(r-l>eps){
        mid=l+(r-l)/2;
        for(j=0;j<n;j++)
            if(!cmn(i,mid,j)){
                l=mid;break;
            }
        if(j==n) r=mid;
    }
    return l;
}
int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lf%lf%lf",&c[i].x,&c[i].y,&c[i].r);
        for(ans=0xfffffff,i=0;i<n;i++)
            ans=min(cal(i),ans);
        printf("%.4f\n",ans);
    }
}
