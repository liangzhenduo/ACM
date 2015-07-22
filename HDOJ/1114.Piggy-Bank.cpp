#include <cstdio>
#include <algorithm>
#define INF 0xfffffff
using namespace std;
int main(){
    int t,n,e,f,v,p[500],w[500],i,j,dp[10001]={0};
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&e,&f,&n);
        for(v=f-e,i=0;i<n;i++)
            scanf("%d%d",&p[i],&w[i]);
        for(i=1;i<=v;i++) dp[i]=INF;
        for(i=0;i<n;i++)
            for(j=w[i];j<=v;j++)
                dp[j]=min(dp[j],dp[j-w[i]]+p[i]);
        if(dp[v]<INF)
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[v]);
        else puts("This is impossible.");
    }
}
