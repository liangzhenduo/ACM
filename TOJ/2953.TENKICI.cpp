#include <stdio.h>
#include <algorithm>
int main()
{
    int n,r[500],c[500],i,k;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d%d",&r[i],&c[i]);
        std::sort(r,r+n);
        std::sort(c,c+n);
        for(i=0,k=0;i<n;i++)
            k+=abs(i+1-r[i])+abs(i+1-c[i]);
        printf("%d\n",k);
    }
}
