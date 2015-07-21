#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char ma[7][8];
int n,m,t,x0,y0,x1,y1,ans,tmp;
int dis[4][2]={0,1,1,0,0,-1,-1,0};
void dfs(int x,int y,int time){
    if(ma[x][y]=='D'&&time==t){
        ans=1;return;
    }
    if(x<0||y<0||x>=n||y>=m||ma[x][y]!='.') return;
    tmp=(t-time)-(abs(x-x1)+abs(y-y1));
    if(tmp%2||tmp<0) return;
    ma[x][y]='X';
    for(int i=0;i<4;i++){
        dfs(x+dis[i][0],y+dis[i][1],time+1);
        if(ans) return;
    }
    ma[x][y]='.';
    return;
}
int main(){
    int i,j,k;
    while(scanf("%d%d%d",&n,&m,&t)&&n){
        for(ans=i=0;i<n;i++)
            scanf("%s",ma[i]);
        for(k=1,i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(ma[i][j]=='S')
                    x0=i,y0=j;
                else if(ma[i][j]=='D')
                    x1=i,y1=j;
                else if(ma[i][j]=='.')
                    k++;
        if(k<t){
            puts("NO");
            continue;
        }
        ma[x0][y0]='.';
        dfs(x0,y0,0);
        puts(ans?"YES":"NO");
    }
}
