#include <cstdio>
int main(){
    int n,i,j;
    long long dp[61][2];
    dp[1][0]=0,dp[1][1]=1;
    dp[2][0]=1,dp[2][1]=1;
    dp[3][0]=2,dp[3][1]=1;
    for(i=4;i<61;i++){
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-3][0]+dp[i-3][1]+1;
    }
    while(~scanf("%d",&n))
        printf("%lld\n",dp[n][0]+dp[n][1]);
}