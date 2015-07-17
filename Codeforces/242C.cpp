#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#define maxn 1000000000
using namespace std;
pair<int,int> tmp;
map<pair<int,int>,int> pnt;
int x,y,stp,x0,y0,x1,y1,dir[8][2]={0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1};
int bfs(){
    queue<pair<pair<int,int>,int> > q;
    q.push(make_pair(make_pair(x0,y0),0));
    while(!q.empty()){
        tmp=q.front().first;
        stp=q.front().second;
        x=tmp.first,y=tmp.second;
        q.pop();
        if(x<1||y<1||x>maxn||y>maxn||pnt[tmp]!=-1) continue;
        if(x==x1&&y==y1)
            return stp;
        pnt[tmp]=stp;
        for(int i=0;i<8;i++){
            tmp=make_pair(x+dir[i][0],y+dir[i][1]);
            q.push(make_pair(tmp,stp+1));
        }
    }
    return -1;
}
int main(){
    int n,r,a,b,i,j;
    while(scanf("%d%d%d%d%d",&x0,&y0,&x1,&y1,&n)!=EOF){
        pnt.clear();
        for(i=0;i<n;i++){
            scanf("%d%d%d",&r,&a,&b);
            for(j=a;j<=b;j++)
                pnt[make_pair(r,j)]=-1;
        }
        printf("%d\n",bfs());
    }
}
