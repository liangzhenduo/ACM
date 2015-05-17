#include <stdio.h>
long long f(int m)
{
    long long sum=0,i;
    for(i=1;i*i<=m;i++)
        sum+=m/i-i+1;
    return sum*2-i+1;
}
int main()
{
    int t,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        printf("%lld\n",f(k));
    }
}
