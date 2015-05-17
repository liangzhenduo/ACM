#include <stdio.h>
int main()
{
	int t,n,k,i;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
        i=1,k=0;
        while(i<n)
        {
            i*=2;
            k++;
        }
        printf("%d\n",k);
    }
}
