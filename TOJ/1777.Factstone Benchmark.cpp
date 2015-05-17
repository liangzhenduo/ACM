#include <stdio.h>
#include <math.h>
int main()
{
    int y;
    while(scanf("%d",&y)&&y)
    {
        int n=(y-1940)/10,m=1;
		double k=pow(2,n)*log10(2),sum=0;
		while(sum<=k)
			sum+=log10(m++);
        printf("%d\n",m-2);
    }
}
