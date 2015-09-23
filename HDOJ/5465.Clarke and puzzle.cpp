#include <cstdio>
#include <cstring>
int mat[501][501],x[501][501];
int main(){
	int t,n,m,q,i,j,o,x0,y0,x1,y1,x2,y2,b,a;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&q);
		memset(x,0,sizeof(x));
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				scanf("%d",&mat[i][j]);
				x[i][j]=x[i][j-1]^mat[i][j];
			}
		}
		while(q--){
			scanf("%d",&o);
			if(o==1){
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				for(a=0,i=x1;i<=x2;i++)
					a=a^x[i][y2]^x[i][y1-1];
				puts(a?"Yes":"No");
			}
			else{
				scanf("%d%d%d",&x0,&y0,&b);
				mat[x0][y0]=b;
				for(j=y0;j<=m;j++)
					x[x0][j]=x[x0][j-1]^mat[x0][j];
			}
		}
	}
}