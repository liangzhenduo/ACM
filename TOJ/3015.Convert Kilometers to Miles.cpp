#include <stdio.h>
int main()
{
    int t,x,k,i,fib[23]={0,1,2};
    for(i=3;i<23;i++)
        fib[i]=fib[i-1]+fib[i-2];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&x);
        int tab[23]={0};
        for(i=22;i>=1;i--)
            if(fib[i]<=x)
                tab[i]++,x-=fib[i];
        for(i=2,k=0;i<24;i++)
            if(tab[i])
                k+=fib[i-1];
        printf("%d\n",k);
    }
}
