#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
vector<int> g[101];
stack<int> s;
int vis[101],low[101],dfs,con,rec[101],in[101],out[101];
void getStrongConnected(int u){
    vis[u]=low[u]=++dfs;
    int n=(int)g[u].size();
    s.push(u);
    for(int i=0;i<n;i++){
        int v=g[u][i];
        if(!vis[v]){
            getStrongConnected(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!rec[v])
            low[u]=min(low[u],low[v]);
    }
    if(vis[u]==low[u]){
        ++con;
        int v;
        do{
            v = s.top();
            s.pop();
            rec[v] = con;
        }while(u!=v);
    }
}
void tarjan(int n){
    dfs=0,con=0;
    memset(vis,0,sizeof(vis));
    memset(low,0,sizeof(low));
    memset(rec,0,sizeof(rec));
    while(!s.empty())
        s.pop();
    for(int i=1;i<=n;i++)
        if(!vis[i])
            getStrongConnected(i);
}
int main(){
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&j);
        while(j){
            g[i].push_back(j);
            scanf("%d",&j);
        }
    }
    tarjan(n);
    for(j=1;j<=n;j++)
        for(i=0;i<(int)g[j].size();i++){
            k=g[j][i];
            if(rec[j]!=rec[k]){
                out[rec[j]]++;
                in[rec[k]]++;
            }
        }
    int zeroIn=0,zeroOut=0;
    for(i=1;i<=con;i++){
        if(in[i]==0) zeroIn++;
        if(out[i]==0) zeroOut++;
    }
    printf("%d\n",zeroIn);
    printf("%d\n",con==1?0:max(zeroIn,zeroOut));
}