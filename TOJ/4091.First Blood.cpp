#include <cstdio>
#include <algorithm>
int main(){
    int n,v,i,j,m[101],h[101],dp[1001];
    while(scanf("%d%d",&n,&v)!=EOF){
        for(i=0;i<n;i++) scanf("%d",&m[i]);
        for(i=0;i<n;i++) scanf("%d",&h[i]);
        for(i=0;i<=v;i++) dp[i]=0;
        for(i=0;i<n;i++)
            for(j=m[i];j<=v;j++)
                dp[j]=std::max(dp[j-m[i]]+h[i],dp[j]);
        printf("%d\n",dp[v]);
    }
}
