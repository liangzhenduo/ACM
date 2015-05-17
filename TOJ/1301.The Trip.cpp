#include <stdio.h>
#include <math.h>
int main()
{
    int n,i;
    double amo[1000],sum,ave,x,y;
    while(scanf("%d",&n)&&n)
    {
        for(i=sum=0;i<n;sum+=amo[i++])
            scanf("%lf",&amo[i]);
        ave=sum/n+0.005;
        ave=floor(100*ave)/100.0;
        for(i=x=y=0;i<n;x+=amo[i]>ave?amo[i]-ave:0,y+=amo[i]<ave?ave-amo[i]:0,i++);
        printf("$%.2lf\n",x>y?y:x);
    }
}
