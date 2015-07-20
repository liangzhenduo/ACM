#include <cstdio>
#include <cmath>
#define PI acos(-1.0)
int main(){
    double r,h,s,v,l;
    while(scanf("%lf",&s)!=EOF){
        r=sqrt(s/(4*PI));
        h=sqrt((s*s)/(PI*PI*r*r)-2*s/PI);
        v=PI*r*r*h/3;
        printf("%.2f\n%.2f\n%.2f\n",v,h,r);
    }
}
