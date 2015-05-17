#include <stdio.h>
long long r[100001],b[100001];
int main()
{
    int t,x=0,n;
    scanf("%d",&t);
    while(t-x)
    {
        long long d=0;
        scanf("%d",&n);
        for(int j=0;j<n;j++)
            scanf("%d%d",&r[j],&b[j]);
        for(int j=1;j<n;j++)
        {
            d+=(r[j]*b[j-1]+b[j]*r[j-1]);
            r[j]+=r[j-1];
            b[j]+=b[j-1];
        }
        printf("Case %d: %lld\n",++x,d);
    }
}
