#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=105;
int sta[64],num[64],map[maxn];
int dp[maxn][64][64];
char s[15];
int main(){
    int n,m,cnt,i,j,k,l,ans;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(map,0,sizeof(map));
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++){
            scanf("%s",s);
            for(j=0;j<m;j++)
                if(s[j]=='H')
                    map[i]+=(1<<j);
        }
        for(cnt=j=0;j<(1<<m);j++){
            int tmp=j;
            if((j&(j<<1))||(j&(j<<2))) continue;
            while(tmp){
                num[cnt]+=(tmp&1);
                tmp>>=1;
            }
            sta[cnt++]=j;
        }
        for(i=0;i<cnt;i++){
            if(map[0]&sta[i]) continue;
            dp[0][i][0]=num[i];
        }
        for(i=0;i<cnt;i++){
            if(map[1]&sta[i]) continue;
            for(j=0;j<cnt;j++){
                if(map[0]&sta[j]) continue;
                if(sta[i]&sta[j]) continue;
                dp[1][i][j]=max(dp[1][i][j],dp[0][j][0]+num[i]);
            }
        }
        for(l=2;l<n;l++)
            for(i=0;i<cnt;i++){
                if(map[l]&sta[i]) continue;
                for(j=0;j<cnt;j++){
                    if(map[l-1]&sta[j]) continue;
                    if(sta[i]&sta[j]) continue;
                    for(k=0;k<cnt;k++){
                        if(map[l-2]&sta[k]) continue;
                        if((sta[i]&sta[k])||(sta[j]&sta[k])) continue;
                        dp[l][i][j]=max(dp[l][i][j],dp[l-1][j][k]+num[i]);
                    }
                }
            }
        for(ans=i=0;i<cnt;i++)
            for(j=0;j<cnt;j++)
                ans=max(ans,dp[n-1][i][j]);
        printf("%d\n",ans);
    }
}