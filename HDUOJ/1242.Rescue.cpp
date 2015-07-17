#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
char ma[200][201];
int vst[200][200],n,m,dir[4][2]={0,1,1,0,0,-1,-1,0},stp;
struct Grid{
    int x,y,step;
    friend bool operator < (Grid p,Grid q){
        return p.step>q.step;
    }
}tmp;
int bfs(int x,int y){
    priority_queue<Grid> q;
    memset(vst,-1,sizeof(vst));
    tmp.x=x,tmp.y=y,tmp.step=0;
    q.push(tmp);
    while(!q.empty()){
        tmp=q.top();
        x=tmp.x,y=tmp.y,stp=tmp.step;
        q.pop();
        if(x<0||y<0||x>=n||y>=m||vst[x][y]>=0||ma[x][y]=='#') continue;
        if(ma[x][y]=='a') return stp;
        if(ma[x][y]=='x') stp++;
        vst[x][y]=stp;
        for(int i=0;i<4;i++){
            tmp.x=x+dir[i][0],tmp.y=y+dir[i][1],tmp.step=stp+1;
            q.push(tmp);
        }
    }
    return -1;
}
int main(){
    int i,j,x,y,ans;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(vst,0,sizeof(vst));
        for(i=0;i<n;i++)
            scanf("%s",ma[i]);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(ma[i][j]=='r')
                    x=i,y=j;
        ans=bfs(x,y);
        printf(ans==-1?"Poor ANGEL has to stay in the prison all his life.\n":"%d\n",ans);
    }
}
