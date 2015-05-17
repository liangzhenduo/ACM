#include <stdio.h>
long long h[65536]={1};
int main()
{
	long long p1,p2,p3,i,j,a,b,c,d,e,f;
	while(scanf("%lld%lld%lld%lld",&p1,&p2,&p3,&i)!=EOF)
	{
		for(j=a=b=c=0;j<i;)
        {
            d=h[a]*p1,e=h[b]*p2,f=h[c]*p3;
            h[++j]=(d<e?d:e)<f?(d<e?d:e):f;
            a+=h[j]-d?0:1,b+=h[j]-e?0:1,c+=h[j]-f?0:1;
        }
        printf("%lld\n",h[i]);
	}
}
