#include <cstdio>
#include <cmath>
#include <algorithm>
#define eps 1e-8
using namespace std;
double x[6],y[6],ans;
double mult(int a,int b,int c){
    return (x[a]-x[c])*(y[b]-y[c])-(x[b]-x[c])*(y[a]-y[c]);
}
bool intersect(){
    if(max(x[0],x[1])<min(x[2],x[3])||max(y[0],y[1])<min(y[2],y[3])||
       max(x[2],x[3])<min(x[0],x[1])||max(y[2],y[3])<min(y[0],y[1])||
       mult(2,1,0)*mult(1,3,0)<0||mult(0,3,2)*mult(3,1,2)<0)
        return false;
    return true;
}
void cross(){
    double a=(y[1]-y[0])*x[0]+(x[0]-x[1])*y[0];
    double b=(y[3]-y[2])*x[2]+(x[2]-x[3])*y[2];
    double d=(x[1]-x[0])*(y[3]-y[2])-(x[3]-x[2])*(y[1]-y[0]);
    double e=b*(x[1]-x[0])-a*(x[3]-x[2]);
    double f=b*(y[1]-y[0])-a*(y[3]-y[2]);
    x[4]=e/d,y[4]=f/d;
}
double area(int i,int j,int k){
    double a=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    double b=sqrt((x[i]-x[k])*(x[i]-x[k])+(y[i]-y[k])*(y[i]-y[k]));
    double c=sqrt((x[k]-x[j])*(x[k]-x[j])+(y[k]-y[j])*(y[k]-y[j]));
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main(){
    int t,i,j,p,q;
    scanf("%d",&t);
    while(t--){
        for(i=0;i<4;i++)
            scanf("%lf%lf",&x[i],&y[i]);
        if(!intersect()) ans=0;
        else{
            cross();
            for(p=q=-1,i=0;i<4;i++){
                if(p<0&&y[i]>y[4]) p=i;
                else if(y[i]>y[4]) q=i;
            }
            if(q==-1) ans=0;
            else if(y[p]<=y[q]){
                y[5]=y[p];
                x[5]=(y[5]-y[2])/(y[3]-y[2])*(x[3]-x[2])+x[2];
                if(x[p]-eps<x[5]&&x[q]-eps<=x[p]||x[p]+eps>x[5]&&x[q]+eps>=x[p]) ans=0;
                else ans=area(p,4,5);
            }
            else{
                y[5]=y[q];
                x[5]=(y[5]-y[0])/(y[1]-y[0])*(x[1]-x[0])+x[0];
                if(x[q]-eps<x[5]&&x[p]-eps<=x[q]||x[q]+eps>x[5]&&x[p]+eps>=x[q]) ans=0;
                else ans=area(q,4,5);
            }
        }
        printf("%.2f\n",ans+eps);
    }
}
