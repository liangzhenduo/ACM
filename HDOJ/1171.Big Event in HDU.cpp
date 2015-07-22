#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[250001];
int main(){
    int n,v[50],m[50],i,j,k,sum,dmd;
    while(scanf("%d",&n)&&n>0){
        for(sum=i=0;i<n;i++){
            scanf("%d%d",&v[i],&m[i]);
            sum+=v[i]*m[i];
        }
        dmd=sum/2;
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
            for(j=1;j<=m[i];j++)
                for(k=dmd;k>=v[i];k--)
                    dp[k]=max(dp[k],dp[k-v[i]]+v[i]);
        printf("%d %d\n",sum-dp[dmd],dp[dmd]);
    }
}
