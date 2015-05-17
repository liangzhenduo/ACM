#include <stdio.h>
int main()
{
	 int n;
	 while(scanf("%d",&n)&&n)
	 {
        int i,k=n;
        for(i=2;i*i<=n;i++)
        if(!(n%i))
        {
            k=k/i*(i-1);
	     	while(!(n%i))
                n/=i;
        }
        if(n>1)
        k=k/n*(n-1);
        printf("%d\n",k);
	 }
}
