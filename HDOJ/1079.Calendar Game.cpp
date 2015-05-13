#include <cstdio>
int main(){
	int t,y,m,d;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&y,&m,&d);
		puts(!(d==30&&m>8)&&(m+d)&1?"NO":"YES");
	}
}