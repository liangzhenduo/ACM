/*
ID: liangzh7
LANG: C++
TASK: subset
*/
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    int n,sum,i,j;
    long long dp[400];
	while(scanf("%d",&n)!=EOF){
        sum=n*(n+1)/2;
        if(sum%2) puts("0");
        else{
            memset(dp,0,sizeof(dp));
            for(sum/=2,dp[0]=i=1;i<=n;i++)
                for(j=sum;j>=i;j--)
                    dp[j]=dp[j]+dp[j-i];
            printf("%d\n",dp[sum]/2);
        }
	}
}
