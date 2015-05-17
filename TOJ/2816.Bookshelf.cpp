#include <stdio.h>
#include <string.h>
#include <algorithm>
int main()
{
    int n,k,a[101],mm[101][101],i,j,l;
    unsigned dp[101][101];
    while(scanf("%d%d",&n,&k)&&n+k)
    {
        memset(dp,255,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            mm[i][i]=a[i];
            dp[i][1]=std::max(int(dp[i-1][1]),a[i]);
        }
        for(i=1;i<n;i++)
            for(j=i+1;j<=n;j++)
                mm[i][j]=std::max(mm[i][j-1],a[j]);
        for(i=2;i<=k;i++)
            for(j=i;j<=n;j++)
                for(l=1;l<=j-i+1;l++)
                    dp[j][i]=std::min(dp[j][i],dp[j-l][i-1]+mm[j-l+1][j]);
        printf("%d\n",dp[n][k]);
    }
}

