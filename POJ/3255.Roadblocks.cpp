#include <cstdio>  
#include <cstring>  
#include <queue>  
using namespace std;  
const int inf=0x3f3f3f3f;
int hed[5001],dis[5001],vis[5001],n,m,cnt;  
struct Node{
    int to,len;
    bool operator<(Node p)const{
        return p.len+dis[p.to]<len+dis[to];  
    }
}cur,tmp;
struct Edge{
    int to,len,nxt;
}e[200001];
void add(int x,int y,int f){  
    e[cnt].to=y;
    e[cnt].len=f;
    e[cnt].nxt=hed[x];
    hed[x]=cnt++;  
}  
void spfa(int s){  
    queue<int> q;
    int i,j,k;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis)); 
    q.push(s);
    vis[s]=1;
    dis[s]=0;
    while(!q.empty()){ 
        i=q.front();
        vis[i]=0;
        q.pop();
        for(j=hed[i];j!=-1;j=e[j].nxt){
            k=e[j].to;
            if(dis[i]+e[j].len<dis[k]){
                dis[k]=dis[i]+e[j].len;
                if(!vis[k]){
                    q.push(k);
                    vis[k]=1;
                }
            }
        }
    }
}
int astar(int k){
    memset(vis,0,sizeof(vis));
    priority_queue<Node> q;
    cur.len=0,cur.to=1;
    q.push(cur);
    while(!q.empty()){
        cur=q.top();
        q.pop();
        vis[cur.to]++;
        if(vis[cur.to]==k)
            return cur.len+dis[cur.to];
        for(int i=hed[cur.to];i!=-1;i=e[i].nxt){
            tmp.len=cur.len+e[i].len;
            tmp.to=e[i].to;
            q.push(tmp);
        }
    }
    return inf;  
}  
int main(){  
    int a,b,c,ans;  
    while(scanf("%d%d",&n,&m)!=EOF){  
        cnt=0;  
        memset(hed,-1,sizeof(hed));  
        while(m--){  
            scanf("%d%d%d",&a,&b,&c);  
            add(b,a,c);
            add(a,b,c);  
        }  
        spfa(n); 
        ans=astar(2);  
        printf("%d\n",ans<inf?ans:-1);
    }  
}