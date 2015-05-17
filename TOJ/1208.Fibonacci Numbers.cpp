#include <stdio.h>
#include <string.h>
struct Fibonacci{
	int len,num[1000];
}fib[4788];
int main()
{
    fib[1].num[0]=1,fib[1].len=1;
    fib[2].num[0]=1,fib[2].len=1;
    int n,i,j,k,l;
    for(i=3;i<4788;i++)
    {
        for(j=0,k=0;j<=fib[i-1].len;j++)
        {
            n=(j<fib[i-2].len?fib[i-2].num[j]:0)+(j<fib[i-1].len?fib[i-1].num[j]:0);
            fib[i].num[j]=(k+n)%10;
            k=(k+n)/10;
        }
        fib[i].len=fib[i].num[fib[i-1].len]?fib[i-1].len+1:fib[i-1].len;
    }
    while(scanf("%d",&n)!=EOF)
    {
    	for(i=fib[n].len-1;i>=0;i--)
    	    printf("%d",fib[n].num[i]);
    	puts("");
    }
}
