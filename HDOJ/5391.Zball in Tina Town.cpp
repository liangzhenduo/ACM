#include <cstdio>
int main(){
	int t,n,i,j,ans;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==4) ans=2;
		else if(n%2==0) ans=0;
		else
			for(ans=n-1,i=3;i*i<=n;i+=2)
				if(n%i==0){
					ans=0;
					break;
				}
		printf("%d\n",ans);
	}
}
