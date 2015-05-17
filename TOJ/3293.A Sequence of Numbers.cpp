#include <stdio.h>
int main()
{
    long long t,a,b,c,k;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
        if(2*b-a-c)
        {
            c/=b,b=1,k--;
            while(k)
            {
                if(k%2)
                    b=b*c%200907;
                c=c*c%200907;
                k/=2;
            }
            a=a*b%200907;
        }
        else
            a=(a+(c-b)*(k-1))%200907;
        printf("%lld\n",a);
    }
}
