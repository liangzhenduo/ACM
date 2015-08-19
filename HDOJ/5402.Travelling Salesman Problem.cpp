#include <cstdio>
#include <cstring>
int main(){
	int n,m,i,j,k,x,y,sum,mini;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(mini=100000,sum=0,i=1;i<=n;i++)
			for(j=1;j<=m;j++){
				scanf("%d",&k);
				sum+=k;
				if((i+j)%2&&k<mini) mini=k,x=i,y=j;
			}
		if(n%2){
			printf("%d\n",sum);
			for(j=1;j<=n;j++){
				for(i=1;i<m;i++){
					printf("%c",j%2?'R':'L');
				}
				if(j==n){
					puts("");break;
				}
				printf("D");
			}
		}
		else if(m%2){
			printf("%d\n",sum);
			for(j=1;j<=m;j++){
				for(i=1;i<n;i++){
					printf("%c",j%2?'D':'U');
				}
				if(j==m){
					puts("");break;
				}
				printf("R");
			}
		}
		else if(x%2){
			printf("%d\n",sum-mini);
			for(j=1;j<y-1;j++){
				for(i=1;i<n;i++){
					printf("%c",j%2?'D':'U');
				}
				printf("R");
			}
			for(j=1;j<x&&j<n;j+=2){
				printf("RDLD");
			}
			printf("D");
			for(++j;j<n;j+=2){
				printf("RDLD");
			}
			printf("R");
			for(i=y+1;i<=m;i++){
				printf("R");
				for(j=1;j<n;j++)
					printf("%c",i%2?'U':'D');
			}
			puts("");
		}
		else if(y%2){
			printf("%d\n",sum-mini);
			for(j=1;j<x-1;j++){
				for(i=1;i<m;i++){
					printf("%c",j%2?'R':'L');
				}
				printf("D");
			}
			for(j=1;j<y&&j<m;j+=2){
				printf("DRUR");
			}
			printf("R");
			for(++j;j<m;j+=2){
				printf("DRUR");
			}
			printf("D");
			for(i=x+1;i<=n;i++){
				printf("D");
				for(j=1;j<m;j++)
					printf("%c",i%2?'L':'R');
			}
			puts("");
		}
	}
}