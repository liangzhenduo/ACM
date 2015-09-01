#include <cstdio>
#include <cstring>
int main(){
	int n,m,u,v,dis[101][101],ans;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(dis,0,sizeof(dis));
		for(int i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			dis[u][v]=1,dis[v][u]=1;
		}
		ans=1;
		if(dis[1][n]==1) ans=n*(n-1)/2;
		printf("1 %d\n",ans);
	}
}