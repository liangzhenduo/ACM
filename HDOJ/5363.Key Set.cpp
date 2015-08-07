#include <cstdio>
const int mod=1000000007;
long long PowerMod(long long a,int b){
    long long ans=1;
    a%=mod;
    while(b>0){
        if(b&1)
        ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
int main(){
	int n,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%lld\n",PowerMod(2,n-1)-1);
	}
}