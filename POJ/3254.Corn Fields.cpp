#include <cstdio>
#include <cstring>
using namespace std;
const int mod=100000000;
int pas[12],sta[1000],dp[12][1000];
int main(){
    int m,n,i,j,k,s,ans;
    while(scanf("%d%d",&m,&n)!=EOF){
	    for(k=1<<n,s=i=0;i<k;i++)
	        if(!(i&(i<<1)))
	            sta[s++]=i;
	    for(i=0;i<m;i++){
	        pas[i]=0;
	        for(j=n-1;j>=0;j--){
	            scanf("%d",&k);
	            pas[i]+=k<<j;
	        }
	    }
	    for(j=0;j<s;j++)
	        dp[0][j]=((pas[0]&sta[j])==sta[j])?1:0;
	    for(i=1;i<m;i++)
	        for(j=0;j<s;j++){
	            if((pas[i]&sta[j])!=sta[j])
	                continue;
	            for(k=0;k<s;k++)
	                if(dp[i-1][k]&&(sta[k]&sta[j])==0)
	                    dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
	        }
	    for(ans=j=0;j<s;j++)
	        if(dp[m-1][j])
	            ans=(ans+dp[m-1][j])%mod;
	    printf("%d\n",ans);
	}
}