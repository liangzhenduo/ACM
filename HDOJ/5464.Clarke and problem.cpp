#include <cstdio>
#include <cstring>
const int mod=1000000007;
int dp[1001][1001];
int main(){
	int t,n,p,m,i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&p);
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(i=1;i<=n;i++){
			scanf("%d",&m);
			m=(m%p+p)%p;
			for(j=0;j<p;j++){
				dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
				dp[i][(j+m)%p]=(dp[i][(j+m)%p]+dp[i-1][j])%mod;
			}
		}
		printf("%d\n",dp[n][0]);
	}
}