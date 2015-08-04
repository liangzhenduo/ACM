#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn=105,inf=0x3f3f3f3f;
int net[maxn][maxn],rec[maxn][maxn];
int vis[maxn],pre[maxn],n,np,nc,m;
int ek(){
    int ans=0,u,v;
    queue<int> q;
    while(1){
        memset(vis,0,sizeof(vis));
        vis[0]=inf;
        q.push(0);
        while(!q.empty()){
            u=q.front();
            q.pop();
            for(v=0;v<=n+1;v++)
                if(!vis[v]&&rec[u][v]>net[u][v]){
                    vis[v]=min(vis[u],rec[u][v]-net[u][v]);
                    pre[v]=u;
                    q.push(v);
                }
        }
        if(vis[n+1]==0) break;
        for(u=n+1;u!=0;u=pre[u]){
            net[pre[u]][u]+=vis[n+1];
            net[u][pre[u]]-=vis[n+1];
        }
        ans+=vis[n+1];
    }
    return ans;
}
int main(){
    int u,v,w,i;
    while(scanf("%d %d %d %d",&n,&np,&nc,&m)!=EOF){
        memset(rec,0,sizeof(rec));
        memset(net,0,sizeof(net));
        for(i=0;i<m;i++){
            scanf(" (%d,%d)%d",&u,&v,&w);
            rec[u+1][v+1]+=w;
        }
        for(i=0;i<np;i++){
            scanf(" (%d)%d",&v,&w);
            rec[0][v+1]+=w;
        }
        for(i=0;i<nc;i++){
            scanf(" (%d)%d",&u,&w);
            rec[u+1][n+1]+=w;
        }
        printf("%d\n",ek());
    }
}

