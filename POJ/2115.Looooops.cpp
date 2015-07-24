#include <cstdio>
#define ll long long
ll x,y;
ll egcd(ll a,ll b){
    if(b==0){
        x=1,y=0;
        return a;
    }
    ll gcd=egcd(b,a%b),tmp=x;
    x=y,y=tmp-a/b*x;
    return gcd;
}
int main(){
    ll a,b,c,k,ans,gcd,maxn;
    while(scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&k)&&a+b+c+k){
        maxn=(ll)1<<k;
        gcd=egcd(c,maxn);
        if((b-a)%gcd) puts("FOREVER");
        else{
            ans=(b-a)/gcd*x;
            ans%=maxn/gcd;
            while(ans<0) ans+=maxn/gcd;
            printf("%I64d\n",ans);
        }
    }
}
