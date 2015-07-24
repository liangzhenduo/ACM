#include <cstdio>
#include <algorithm>
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
    int t,n,m,i,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(i=1;i<n;i++){
            scanf("%d",&k);
            if(m<k) std::swap(m,k);
            m=m/gcd(m,k)*k;
        }
        printf("%d\n",m);
    }
}
