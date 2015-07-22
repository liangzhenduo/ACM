#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    int t,n,m,p[100],h[100],c[100],dp[101],i,j,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
            scanf("%d%d%d",&p[i],&h[i],&c[i]);
        memset(dp,0,sizeof(dp));
        for(i=0;i<m;i++)
            for(j=1;j<=c[i];j++)
                for(k=n;k>=p[i];k--)
                    dp[k]=max(dp[k],dp[k-p[i]]+h[i]);
        printf("%d\n",dp[n]);
    }
}
