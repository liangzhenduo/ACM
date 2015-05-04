#include <cstdio>
#define ll long long
ll f[100005]={1,1},ny[100005]={1,1},fac[100005]={1,1};
const int mod=1000000007;
ll c(ll n,ll m){
	return n<m?0:fac[n]*ny[m]%mod*ny[n-m]%mod;
}
ll solve(ll n,ll m,ll k){
	if(m==3){
		if(k<=1) return 0;
		if(k==2) return (c(n,m)-n*(n/2+1)*(n/2)/6%mod+mod)%mod;
		if(k==3) return n*(n/2+1)*(n/2)/6%mod;
	}
	if(k>2) return 0;
	if(k==2) return n*(c(n/2+1,m-1)+c(n/2,m-1))%mod;
	if(k==1) return n*(m-4)%mod*c(n/2+1,m-1)%mod;
	return (c(n,m)-n*(c(n/2+1,m-1)+c(n/2,m-1))%mod-n*(m-4)%mod*c(n/2+1,m-1)%mod+2*mod)%mod;
}
int main(){
	int cas=0,t,i;
	for(i=2;i<100001;i++){
		fac[i]=fac[i-1]*i%mod;
		ll t=mod/i,s=mod%i;
        f[i]=i*t%mod*t%mod*f[s]%mod*f[s]%mod;
		ny[i]=ny[i-1]*f[i]%mod;
	}
	ll n,m,k;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld",&n,&m,&k);
		printf("Case #%d: %lld\n",++cas,solve(n,m,k));
	}
}