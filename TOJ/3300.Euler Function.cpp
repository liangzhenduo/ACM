#include <stdio.h>
#define maxn 3000001
int phi[maxn];
int main()
{
	int i,j,a,b;
	for(i=1;i<=maxn;i++)
	    phi[i]=i;
	for(i=2;i<=maxn;i+=2)
	    phi[i]/=2;
	for(i=3;i<=maxn;i+=2)
	    if(phi[i]==i)
	    	for(j=i;j<=maxn;j+=i)
	    	    phi[j]=phi[j]/i*(i-1);
    while(scanf("%d%d",&a,&b)==2)
    {
        long long k=0;
	 	for(i=a;i<=b;i++)
            k+=phi[i];
	 	printf("%lld\n",k);
    }
}
