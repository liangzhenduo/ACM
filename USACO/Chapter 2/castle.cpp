/*
ID: liangzh7
LANG: C++
TASK: castle
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
char map[102][102],d;
int a,id[102][102],k;
pair<int,int> area;
vector<pair<int,int> > room;
void dfs(int i,int j){
    if(id[i][j]==0){
        map[i][j]=' ';
        id[i][j]=k;
        a++;
    }
    else return;
    if(map[i-1][j]!='#') dfs(i-2,j);
    if(map[i+1][j]!='#') dfs(i+2,j);
    if(map[i][j-1]!='#') dfs(i,j-2);
    if(map[i][j+1]!='#') dfs(i,j+2);
    return;
}
bool cmp1(pair<int,int> p,pair<int,int> q){
    return p.second>q.second;
}
bool cmp2(pair<int,int> p,pair<int,int> q){
    return p.first<q.first;
}
int main(){
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    int m,n,i,j,max,mix,x,y;
	while(scanf("%d%d",&m,&n)!=EOF){
        room.clear();
        memset(map,'.',sizeof(map));
        memset(id,0,sizeof(id));
        for(i=0;i<n;i++)
            for(j=0;j<m;j++){
                scanf("%d",&k);
                if(k>7) k-=8,map[2*i+2][2*j]=map[2*i+2][2*j+1]=map[2*i+2][2*j+2]='#';
                if(k>3) k-=4,map[2*i][2*j+2]=map[2*i+1][2*j+2]=map[2*i+2][2*j+2]='#';
                if(k>1) k-=2,map[2*i][2*j]=map[2*i][2*j+1]=map[2*i][2*j+2]='#';
                if(k>0) k-=1,map[2*i][2*j]=map[2*i+1][2*j]=map[2*i+2][2*j]='#';
            }
        for(k=0,i=1;i<2*n;i+=2)
            for(j=1;j<2*m;j+=2)
                if(map[i][j]=='.'){
                    k++;
                    a=0;
                    dfs(i,j);
                    area=make_pair(k,a);
                    room.push_back(area);
                }
        sort(room.begin(),room.end(),cmp1);
        printf("%d\n%d\n",room.size(),room[0].second);
        sort(room.begin(),room.end(),cmp2);
        for(d='N',max=0,j=1;j<2*m;j++){
            for(i=2*n;i>0;i--){
                if(map[i][j]!='#') continue;
                if(map[i-1][j]==' '&&map[i+1][j]==' '&&id[i-1][j]!=id[i+1][j]){
                    mix=room[id[i-1][j]-1].second+room[id[i+1][j]-1].second;
                    if(max<mix){
                        max=mix;
                        x=i/2+1,y=j/2+1;
                        d='N';
                    }
                }
                else if(map[i][j-1]==' '&&map[i][j+1]==' '&&id[i][j-1]!=id[i][j+1]){
                    mix=room[id[i][j-1]-1].second+room[id[i][j+1]-1].second;
                    if(max<mix){
                        max=mix;
                        x=i/2+1,y=j/2;
                        d='E';
                    }
                }
            }
        }
        printf("%d\n%d %d %c\n",max,x,y,d);
	}
}
