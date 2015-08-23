#include <cstdio>
#define ll long long
const int mod=987654321;
int main(){
    ll n,m,ans,i;
    while(scanf("%lld%lld",&n,&m)&&n+m>0){
        ans=1;
        if(m==1);
        else if(m==2||m>n)
            while(n){
                if(n&1) ans=ans*m%mod;
                m=m*m%mod;
                n>>=1;
            }
        else{
            for(i=2;i<=m;i++)
                ans=ans*i%mod;
            ans=(ans+m)%mod;
        }
        printf("%lld\n",ans);
    }
}