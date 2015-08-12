#include <cstdio>
int main(){
	int c,n,i;
	long long a[21]={0,0,1},b[21]={0,1,2};
	for(i=3;i<21;i++)
		a[i]=(i-1)*(a[i-1]+a[i-2]),b[i]=i*b[i-1];
	scanf("%d",&c);
	while(c--){
		scanf("%d",&n);
		printf("%.2f",100.0*a[n]/b[n]);
		puts("%");
	}
}