#include <cstdio>
int main(){
    long long t,n,b,i;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&b);
        for(i=0;i<9973;i++)
            if((n-b*i)%9973==0){
                printf("%lld\n",i);
                break;
            }
    }
}
