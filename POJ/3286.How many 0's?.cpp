#include <cstdio>
long long solve(long long n){
	long long tmp=1,ans=1,k=n/10;
	while(k){
		ans+=(k-1)*tmp;
		if(n-tmp*k*10+1>=tmp) ans+=tmp;
		else ans+=n-tmp*k*10+1;
		tmp*=10;k/=10;
	}
	return ans;
}
int main(){
	long long n,m,ans;
	while(scanf("%lld%lld",&m,&n)&&m>-1){
		ans=solve(n);
		ans-=(m>0?solve(m-1):0);
		printf("%lld\n",ans);
	}
}