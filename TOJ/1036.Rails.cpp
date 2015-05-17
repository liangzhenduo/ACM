#include <stdio.h>
#include <string.h>
int main()
{
	int n,coa[1000]={1},use[1001],i,j,k;
	while(scanf("%d",&n)&&n)
	{
		while(scanf("%d",&coa[0])&&coa[0])
		{
			memset(use,0,sizeof(use));
			use[coa[0]]++;
			for(i=1,k=0;i<n;i++)
			{
			    scanf("%d",&coa[i]);
			    if(coa[i]<coa[i-1])
	        	    for(j=coa[i-1];j>coa[i];j--)
	                	k+=use[j]?0:1;
            	use[coa[i]]++;
			}
		    puts(k?"No":"Yes");
	    }
	    puts("");
    }
}
