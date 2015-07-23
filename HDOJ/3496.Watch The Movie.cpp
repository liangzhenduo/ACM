#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[1001][1001];
int main(){
    int t,n,m,l,tim[1000],val[1000],i,j,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&l);
        for(i=0;i<n;i++)
            scanf("%d%d",&tim[i],&val[i]);
        memset(dp,-1,sizeof(dp));
        for(dp[0][0]=i=0;i<n;i++)
            for(j=m;j>0;j--)
                for(k=l;k>=tim[i];k--)
                    if(dp[j-1][k-tim[i]]>=0)
                        dp[j][k]=max(dp[j][k],dp[j-1][k-tim[i]]+val[i]);
        for(k=j=0;j<=l;j++) k=max(k,dp[m][j]);
        printf("%d\n",k);
    }
}
