#include <cstdio>
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	int n,m,g;
	while(~scanf("%d%d",&n,&m)){
		g=gcd(n+m,n*m);
		printf("%d/%d\n",n*m/g,(n+m)/g);
	}
}