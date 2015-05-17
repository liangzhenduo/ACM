#include <stdio.h>
#include <math.h>
int main()
{
    int t=0,x;
    double w,d;
    while(scanf("%lf%lf",&w,&d)&&w+d)
    {
        x=int(5730*log2(w*810/d));
        x=x<10000?(x+50)/100*100:(x+500)/1000*1000;
        printf("Sample #%d\nThe approximate age is %d years.\n\n",++t,x);
    }
}
