#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=105;
bool win[maxn][maxn],rlt[maxn][maxn];
int v[maxn];
int main(){
    int t,c=0,n,i,j,k,l,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&v[i]);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&win[i][j]);
        for(i=1;i<=n;i++)
            win[0][i]=win[n+1][i]=0,
            win[i][0]=win[i][n+1]=1;
        memset(rlt,0,sizeof(rlt));
        for(i=0;i<=n+1;i++)
            rlt[i][i+1]=rlt[i][i]=1;
        for(k=2;k<=n;k++)
            for(i=0;i<=n-k+1;i++)
                for(j=i+k,l=i+1;l<=j-1;l++)
                    if(rlt[i][l]&&rlt[l][j]){
                        if(win[i][l])
                            rlt[i][j]=1;
                        if(win[j][l])
                            rlt[i][j]=1;
                    }
        for(ans=0,i=1;i<=n;i++)
            if(rlt[0][i]&&rlt[i][n+1]&&v[i]>ans)
                ans=v[i];
        printf("Case %d: %d\n",++c,ans);
    }
}
