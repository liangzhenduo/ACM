#include <stdio.h>
#include <math.h>
int main(){
    double r,x1,y1,x2,y2,d;
    while(scanf("%lf%lf%lf%lf%lf",&r,&x1,&y1,&x2,&y2)!=EOF){
        if(fabs(x2-x1)>10000||fabs(y2-y1)>10000)
            r=r/100,x1/=100,x2/=100,y1/=100,y2/=100;
        d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        for(long long i=d/2/r;;i++)
            if(2*i*r>=d){
                printf("%d\n",i);
                break;
            }
    }
}
