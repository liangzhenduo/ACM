#include <stdio.h>
int main()
{
    long long n,t;
    while(scanf("%lld",&n)&&n)
    {
        t=1;
        while(t<n)
            t=t*10+1;
        while(n%t)
            t=(t-1)/10;
        printf("%lld\n",n/t);
    }
}
