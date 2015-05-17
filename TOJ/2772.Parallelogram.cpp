#include <cstdio>
int main(){
	int t,i,j,x[4],y[4];
	scanf("%d",&t);
	while(t--){
		for(i=0;i<4;i++)
			scanf("%d%d",&x[i],&y[i]);
		if((x[2]-x[0])*(y[1]-y[3])==(y[2]-y[0])*(x[1]-x[3])&&(x[1]-x[2])*(y[3]-y[0])==(y[1]-y[2])*(x[3]-x[0]))
            puts("Yes");
        else puts("No");
	}
}
