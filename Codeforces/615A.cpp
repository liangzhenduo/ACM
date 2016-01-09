#include <cstdio>
#include <cstring>
int b[101];
int main(){
	int n,m,x,y,flag;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(b,0,sizeof(b));
		while(n--){
			scanf("%d",&x);
			while(x--){
				scanf("%d",&y);
				b[y]++;
			}
		}
		flag=1;
		for(int i=1;i<=m;i++)
			if(b[i]==0){
				puts("NO");
				flag=0;
				break;
			}
		if(flag) puts("YES");
	}
}