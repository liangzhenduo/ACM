#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int inf=0xfffffff;
struct Edge{
    int to,w,nxt;
}edge1[100001],edge2[100001];
struct Node{
    int to,g,f;
    bool operator < (const Node &r) const{
        if(r.f==f) return r.g<g;
        return r.f<f;
    }
}e,ne;
int vis[1000],dis[1001];
int head1[1001],head2[1001];
int astar(int start,int end,int n,int k){
    int cnt=0;
    if(start==end) k++;
    if(dis[start]==inf) return -1;
    e.to=start;
    e.g=0;
    e.f=e.g+dis[e.to];
    priority_queue<Node> q;
    q.push(e);
    while(!q.empty()){
        e=q.top();
        q.pop();
        if(e.to==end) cnt++;
        if(cnt==k) return e.g;
        for(int i=head1[e.to];i!=-1;i=edge1[i].nxt){
            ne.to=edge1[i].to;
            ne.g=e.g+edge1[i].w;
            ne.f=ne.g+dis[ne.to];
            q.push(ne);
        }
    }
    return -1;
}
void spfa(int s,int n){
    for(int i=0;i<=n;i++)
        dis[i]=inf;
    memset(vis,0,sizeof(vis));
    vis[s]=1,dis[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head2[u];i!=-1;i=edge2[i].nxt){
            int tmp=dis[u]+edge2[i].w;
            if(tmp<dis[edge2[i].to]){
                dis[edge2[i].to]=tmp;
                if(!vis[edge2[i].to]){
                    vis[edge2[i].to]=1;
                    q.push(edge2[i].to);
                }
            }
        }
    }
}
int main(){
    int n,m,u,v,w,s,t,k,i;
    while(~scanf("%d%d",&n,&m)){
        memset(edge1,0,sizeof(edge1));
        memset(edge2,0,sizeof(edge2));
        memset(head1,-1,sizeof(head1));
        memset(head2,-1,sizeof(head2));
        for(i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            edge1[i].to=v;
            edge1[i].w=w;
            edge1[i].nxt=head1[u];
            head1[u]=i;
            edge2[i].to=u;
            edge2[i].w=w;
            edge2[i].nxt=head2[v];
            head2[v]=i;
        }
        scanf("%d%d%d",&s,&t,&k);
        spfa(t,n);
        printf("%d\n",astar(s,t,n,k));
    }
}