#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i,a,b;
    while(scanf("%d",&n)&&n)
    {
        long long k;
        for(i=b=k=0;i<n;i++)
        {
            scanf("%d",&a);
            b+=a;
            k+=abs(b);
        }
        printf("%lld\n",k);
    }
}
