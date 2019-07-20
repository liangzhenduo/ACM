#include <cstdio>
#include <cstring>
char grid[505][505];
int r[505][505],c[505][505];
int main(){
	int w,h,r1,c1,r2,c2,q,i,j,k;
	while(scanf("%d%d",&h,&w)!=EOF){
		for(i=0;i<h;i++)
			scanf("%s",grid[i]);
		memset(r,0,sizeof(r));
		memset(c,0,sizeof(c));
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				if(grid[i][j]=='.'&&i<h-1&&grid[i+1][j]=='.')
					r[i+1][j+1]=r[i][j+1]+1;
				else
					r[i+1][j+1]=r[i][j+1];
				if(grid[i][j]=='.'&&j<w-1&&grid[i][j+1]=='.')
					c[i+1][j+1]=c[i+1][j]+1;
				else
					c[i+1][j+1]=c[i+1][j];
			}
		}
		scanf("%d",&q);
		while(q--){
			scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
			int ans=0;
			for(i=c1;i<=c2;i++){
				ans+=(r[r2-1][i]-r[r1-1][i]);
			}
			for(i=r1;i<=r2;i++){
				ans+=(c[i][c2-1]-c[i][c1-1]);
			}
			printf("%d\n",ans);
		}
	}
} 