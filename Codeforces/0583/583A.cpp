#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int n,x,y;
	int h[51],v[51];
	while(scanf("%d",&n)!=EOF){
		int m=n*n;
		memset(h,0,sizeof(h));
		memset(v,0,sizeof(v));
		for(int i=1,j=0;i<=m;i++){
			scanf("%d%d",&x,&y);
			if(!h[x]&&!v[y]){
				h[x]++,v[y]++;
				printf("%d",i);
				printf(++j<n?" ":"\n");
			}
		}
	}
}