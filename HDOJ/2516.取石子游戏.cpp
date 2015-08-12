#include <cstdio>
int main(){
	int n,fib[46]={1,1},i,j;
	for(i=2;i<46;i++)
		fib[i]=fib[i-1]+fib[i-2];
	while(scanf("%d",&n)&&n){
		int l=1,r=45,mid,ans=0;
		while(l<=r){
			mid=l+(r-l)/2;
			if(n==fib[mid]){
				ans=1;break;
			}
			else if(n<fib[mid]) r=mid-1;
			else l=mid+1;
		}
		if(ans) puts("Second win");
		else puts("First win");
	}
}