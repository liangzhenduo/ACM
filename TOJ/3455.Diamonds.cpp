#include <stdio.h>
#include <string.h>
#include <algorithm>
int main()
{
    int t,sum,i,j,v[11],dp[5001];
    scanf("%d",&t);
    while(t--)
    {
        for(i=1,sum=0;i<=10;i++)
        {
            scanf("%d",&v[i]);
            sum+=v[i];
        }
        memset(dp,0,sizeof(dp));
        for(i=1;i<=10;i++)
            for(j=sum/2;j>=v[i];j--)
                dp[j]=std::max(dp[j],dp[j-v[i]]+v[i]);
        printf("%d\n",dp[sum/2]);
    }
}
