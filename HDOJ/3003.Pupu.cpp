#include <cstdio>
long long n;
long long pow(long long m){
    if(m==0) return 1;
    else if(m%2)
        return pow(m/2)*pow(m/2)*2%n;
    else
        return pow(m/2)*pow(m/2)%n;
}
int main(){
    while(scanf("%lld",&n)&&n)
        printf("%lld\n",(pow(n-1)+1)%n);
}
