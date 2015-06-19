#include <cstdio>
using namespace std;
int main(){
    long long n,m,i,j,k;
    while(scanf("%lld",&n)!=EOF){
        m=0,i=9,j=1,k=1;
        while(n>=i){
            m+=j*9*k;
            k*=10;
            j++;
            i=i*10+9;
        }
        m+=(n-(i-9)/10)*j;
        printf("%lld\n",m);
    }
}
