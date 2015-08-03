#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=201,inf=0x3f3f3f3f;
int net[maxn][maxn],pre[maxn],n,m;
bool vis[maxn];
bool bfs(){
    queue<int>q;
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    q.push(1);
    while(!q.empty()){
        int top=q.front();
        if(top==m)
            return true;
        q.pop();
        for(int i=1;i<=m;i++)
            if(!vis[i]&&net[top][i]){
                q.push(i);
                vis[i]=1;
                pre[i]=top;
            }
    }
    return false;
}
int ek(){
    int ans=0;
    while(bfs()){
        int mini=inf,i;
        for(i=m;i>1;i=pre[i])
            mini=min(mini,net[pre[i]][i]);
        for(i=m;i>1;i=pre[i]){
            net[pre[i]][i]-=mini;
            net[i][pre[i]]+=mini;
        }
        ans+=mini;
    }
    return ans;
}
int main(){
    int u,v,c;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(net,0,sizeof(net));
        while(n--){
            scanf("%d%d%d",&u,&v,&c);
            net[u][v]+=c;
        }
        printf("%d\n",ek());
    }
}
