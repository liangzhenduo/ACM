#include <stdio.h>
int main()
{
	int n,i,k;
	while(scanf("%d",&n)&&n)
    {
		printf("%d : ",n);
		for(i=2,k=0;i*i<=n;i++)
        {
            k+=n%i?0:1;
			while(n%i==0)
                n/=i;
		}
		k+=n-1?1:0;
		printf("%d\n",k);
	}
}
