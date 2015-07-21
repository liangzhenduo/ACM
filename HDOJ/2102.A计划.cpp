#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
char ma[2][10][11];
int vst[2][10][10],n,m,t,dis[4][2]={0,1,1,0,0,-1,-1,0},ans;
struct Sta{
    int x,y,z,step;
}sta,tmp;
void bfs(){
    queue<Sta> q;
    memset(vst,0,sizeof(vst));
    sta.x=0,sta.y=0,sta.z=0,sta.step=0;
    q.push(sta);
    while(!q.empty()){
        sta=q.front();
        q.pop();
        if(ma[sta.z][sta.x][sta.y]=='#'){
            vst[sta.z][sta.x][sta.y]++,sta.z=sta.z?0:1;
            if(ma[sta.z][sta.x][sta.y]=='#') continue;
        }
        if(sta.x<0||sta.y<0||sta.x>=n||sta.y>=m||vst[sta.z][sta.x][sta.y]||
           sta.step>t||ma[sta.z][sta.x][sta.y]=='*') continue;
        if(ma[sta.z][sta.x][sta.y]=='P'){
            ans=1;return;
        }
        vst[sta.z][sta.x][sta.y]++;
        for(int i=0;i<4;i++){
            tmp.x=sta.x+dis[i][0];
            tmp.y=sta.y+dis[i][1];
            tmp.step=sta.step+1;
            tmp.z=sta.z;
            q.push(tmp);
        }
    }
}
int main(){
    int c,i,j;
    scanf("%d",&c);
    while(c--){
        memset(vst,0,sizeof(vst));
        scanf("%d%d%d",&n,&m,&t);
        for(ans=j=0;j<2;j++)
            for(i=0;i<n;i++)
                scanf("%s",ma[j][i]);
        bfs();
        puts(ans?"YES":"NO");
    }
}
