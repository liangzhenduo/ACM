#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=205;
const int inf=0xfffffff;
struct Node{
    int x,y;
}hos[101],man[101];
int con[maxn][maxn],cst[maxn][maxn];
int pre[maxn],dis[maxn];
bool vis[maxn];
int dist(Node a,Node b){
    return fabs(a.x-b.x)+fabs(a.y-b.y);
}
bool spfa(int s,int t){
    queue<int> q;
    for(int i=0;i<maxn;i++)
        dis[i]=inf;
    memset(pre,0,sizeof(pre));
    memset(vis,0,sizeof(vis));
    dis[s]=0;
    vis[s]=1;
    q.push(s);
    while(!q.empty()){
        int u=q.front(),v;
        q.pop();
        vis[u]=0;
        for(v=s;v<=t;v++){
            if(!con[u][v]) continue;
            if(dis[v]>dis[u]+cst[u][v]){
                dis[v]=dis[u]+cst[u][v];
                pre[v]=u;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    return dis[t]<inf;
}
int mcmf(int s,int t){
    int ans=0;
    while(spfa(s,t)){
        int mini=inf,i;
        for(i=t;i!=s;i=pre[i])
            if(mini>con[pre[i]][i])
                mini=con[pre[i]][i];
        for(i=t;i!=s;i=pre[i]){
            con[i][pre[i]]+=mini;
            con[pre[i]][i]-=mini;
            ans+=cst[pre[i]][i]*mini;
        }
    }
    return ans;
}
int main(){
    int n,m,i,j,nh,nm;
    char c[101];
    while(scanf("%d%d",&n,&m)&&n){
        for(nh=nm=i=0;i<n;i++){
            scanf("%s",c);
            for(j=0;j<m;j++){
                if(c[j]=='H')
                    hos[nh].x=i,hos[nh].y=j,++nh;
                else if(c[j]=='m')
                    man[nm].x=i,man[nm].y=j,++nm;
            }
        }
        memset(con,0,sizeof(con));
        memset(cst,0,sizeof(cst));
        for(i=1;i<=nh;i++){
            con[0][i]=1;
            for(j=nh+1;j<=nh+nm;j++){
                con[j][nh+nm+1]=1;
                con[i][j]=1;
                cst[i][j]=dist(hos[i-1],man[j-nh-1]);
                cst[j][i]=-cst[i][j];
            }
        }
        printf("%d\n",mcmf(0,nh+nm+1));
    }
}