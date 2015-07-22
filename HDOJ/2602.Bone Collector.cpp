#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    int t,n,v,vol[1000],val[1000],i,j,dp[1000];
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&v);
        for(i=0;i<n;i++)
            scanf("%d",&val[i]);
        for(i=0;i<n;i++)
            scanf("%d",&vol[i]);
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++){
            for(j=v;j>=0;j--)
                if(j>=vol[i])
                    dp[j]=max(dp[j],dp[j-vol[i]]+val[i]);
        }
        printf("%d\n",dp[v]);
    }
}
