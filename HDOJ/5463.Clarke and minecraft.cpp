#include <cstdio>
#include <cstring>
int mat[501];
int main(){
	int t,n,i,j,k;
	scanf("%d",&t);
	while(t--){
		memset(mat,0,sizeof(mat));
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d%d",&j,&k);
			mat[j]+=k;
		}
		int ans=0;
		for(i=1;i<501;i++){
			if(mat[i]%64)
				ans+=(mat[i]/64+1);
			else 
				ans+=(mat[i]/64);
		}
		printf("%d\n",ans%36?ans/36+1:ans/36);
	}
}