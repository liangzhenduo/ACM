#include <stdio.h>
#include <algorithm>
int main()
{
    int k,i,j;
    double a[20],sum;
    while(scanf("%d",&k)&&k)
    {
        for(i=0;i<k;i++)
            scanf("%lf",&a[i]);
        std::sort(a,a+k);
        for(i=j=1,sum=a[0];j&&i<k;sum+=a[i++])
            j-=sum<a[i]?0:1;
        puts(j?"NO":"YES");
    }
}
