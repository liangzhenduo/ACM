#include <stdio.h>
#include <algorithm>
int main()
{
    int t,n,i,j;
    long long dp[101]={0,0,1,7,4,2,6,8};
    for(i=8;i<101;i++)
        dp[i]=9223372036854775807;
    int cost[10]={6,2,5,5,4,5,6,3,7,6};
    for(i=2;i<101;i++)
        for(j=0;j<10;j++)
            if(i+cost[j]<101)
                dp[i+cost[j]] =std::min(dp[i+cost[j]],dp[i]*10+j);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld ",dp[n]);
        if(n%2)
            printf("7"),n-=3;
        for(i=n/2-1;i>=0;i--)
            printf("1");
        printf("\n");
    }
}
