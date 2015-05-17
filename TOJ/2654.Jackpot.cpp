#include <stdio.h>
long long gcd(long long a,long long b)
{
    return b?gcd(b,a%b):a;
}
long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    int n,w,i,k;
    long long p[6]={1};
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&w);
        for(i=1;i<=w;i++)
        {
            scanf("%lld",&p[i]);
            p[i]=lcm(p[i],p[i-1]);
        }
        printf(p[w]>1000000000?"More than a billion.\n":"%d\n",p[w]);
    }
}
