#include <cstdio>
#include <queue>
using namespace std;
char map[100][101];
int n,m,i,j,k,hash[4][100][100];
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
struct Move{
    int x,y,dir,step;
}tmp,cur;
int bfs(int sx,int sy,int tx,int ty){
    queue<Move> Q;
    cur.x=sx,cur.y=sy;
    cur.dir=1;
    cur.step=0;
    Q.push(cur);
    while(!Q.empty()){
        cur=Q.front();
        Q.pop();
        for(i=0;i<4;i++){
            tmp.x=cur.x+dx[i],tmp.y=cur.y+dy[i];
            if(tmp.x>=0&&tmp.y>=0&&tmp.x<n&&tmp.y<m&&map[tmp.x][tmp.y]!='#'){
                tmp.step=cur.step+1;
                tmp.dir=i;
                if(cur.dir-i) tmp.step++;
                if(/*(i==0&&cur.dir==1)||(i==1&&cur.dir==0)||(i==2&&cur.dir==3)||(i==3&&cur.dir==2)*/i+cur.dir==1||i+cur.dir==5)tmp.step++;
                if(tmp.step<hash[i][tmp.x][tmp.y]){
                    Q.push(tmp);
                    hash[i][tmp.x][tmp.y]=tmp.step;
                }
            }
        }
    }
    for(j=0,i=0xfffffff;j<4;j++)
        i=i>hash[j][tx][ty]?hash[j][tx][ty]:i;
    if(i<0xfffffff) return i;
    return -1;
}
int main(){
    int t,sx,sy,tx,ty;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        for(i=0;i<m;i++){
            scanf("%s",map[i]);
            for(j=0;j<n;j++){
                if(map[i][j]=='S') sx=i,sy=j;
                else if(map[i][j]=='T') tx=i,ty=j;
                for(k=0;k<4;k++)
                    hash[k][i][j]=0xfffffff;
            }
        }
        for(k=0;k<4;k++)
            hash[k][sx][sy]=0;
        printf("%d\n",bfs(sx,sy,tx,ty));
    }
}
