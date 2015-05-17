#include <stdio.h>
using namespace std;

    int gcd(int n,int m)
    {
        while(n!=m)
        {
            if(n>m)
                n-=m;
            else
                m-=n;
        }
        return n;
    }

int main()
{
    int t,n,m,s;
    scanf("%d",&t);
    while(t--)
    {
        int k=0;
        scanf("%d %d",&n,&m);
        s=gcd(n,m);
        for(int i=1;i<s/2+2;i++)
            if(n%i==0&&m%i==0)
                k++;
        if(n%s==0&&m%s==0)
            k++;
        printf("%d\n",k);
    }
    return 0;
}
