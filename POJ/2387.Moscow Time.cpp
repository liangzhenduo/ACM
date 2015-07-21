#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 0xfffffff
using namespace std;
int t,n,ma[1001][1001],vis[1001],dis[1001];
int spfa(int s){
	queue<int> q;
	dis[s]=0,vis[s]=1,q.push(s);
	while(!q.empty()){
		int k=q.front();
		q.pop();
		for(int i=1;i<=n;i++)
			if(dis[k]<dis[i]-ma[k][i]){
				dis[i]=dis[k]+ma[k][i];
				if(!vis[i])
					vis[i]=1,q.push(i);
			}
		vis[k]=0;
	}
	return dis[1];
}
int main(){
    int i,j,a,b,c;
	while(scanf("%d%d",&t,&n)!=EOF){
		for(i=1;i<=1001;i++){
			dis[i]=INF;
			for(j=1;j<=1001;j++)
				ma[i][j]=INF;
		}
		memset(vis,0,sizeof(vis));
		while(t--){
			scanf("%d%d%d",&a,&b,&c);
			ma[a][b]=ma[b][a]=min(ma[a][b],c);
		}
		printf("%d\n",spfa(n));
	}
}
