#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0xfffffffffffffff
long long l,r,n;
void ser(long long l,long long r){
    if(l<0||l>r) return;
    if(l==0){
        n=std::min(n,r);return;
    }
    long long len=r-l+1;
    if(l<len) return;
    ser(l,r+len);
    if(len!=1) ser(l,r+len-1);
    ser(l-len,r);
    ser(l-len-1,r);
}
int main(){
    while(scanf("%lld%lld",&l,&r)!=EOF){
        if(!(0<=l&&r>=l&&r<=1e9&&(l/(r-l+1)<=2015))){
            puts("-1");continue;
        }
        n=INF;
        ser(l,r);
        printf("%lld\n",n<INF?n:-1);
    }
}
