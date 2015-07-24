#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[101][101];
int main(){
    int n,m,k,s,a[100],b[100],i,j,l;
    while(scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF){
        for(i=0;i<k;i++)
            scanf("%d%d",&a[i],&b[i]);
        memset(dp,0,sizeof(dp));
        for(dp[0][0]=i=0;i<k;i++)
            for(j=1;j<=s;j++)
                for(l=b[i];l<=m;l++)
                    dp[j][l]=max(dp[j][l],dp[j-1][l-b[i]]+a[i]);
        for(i=0;i<=m;i++)
            if(dp[s][i]>=n) break;
        printf("%d\n",dp[s][i]<n?-1:m-i);
    }
}
