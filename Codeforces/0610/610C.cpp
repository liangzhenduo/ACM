#include <cstdio>
#include <cstring>
int tab[520][520];
int main(){
	int k;
	while(scanf("%d",&k)!=EOF){
		int n=1<<k,i,j=1,l;
		for(i=0;i<n;i++)
			tab[0][i]=1;
		while(k--){
			for(i=0;i<j;i++)
				for(l=0;l<n;l++)
					tab[i+j][l]=l%(n/j)<n/j/2?tab[i][l]:-tab[i][l];
			j<<=1;
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				printf(tab[i][j]>0?"+":"*");
			puts("");
		}
	}
}