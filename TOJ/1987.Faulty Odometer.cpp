#include <stdio.h>
int main()
{
    int n,k,i,m;
    while(scanf("%d",&n)&&n)
    {
        printf("%d: ",n);
        for(i=1,m=0;n;i*=9,n/=10)
            m+=n%10<4?n%10*i:(n%10-1)*i;
        printf("%d\n",m);
    }
}
