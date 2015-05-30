#include <cstdio>
#include <cmath>
using namespace std;
long long power(long long a,long long b){
    if(!b) return 1;
	return b%2?a*power(a,b-1):power(a,b/2)*power(a,b/2);
}
int main(){
    long long n,i,j;
    while(scanf("%lld",&n)&&n){
        for(i=33;i>1;i--){
            j=(long long)(pow(fabs(n),1.0/i)+0.1);
            if(power(j,i)==abs(n)) break;
        }
        if(n<0) while(i%2==0) i/=2;
        printf("%lld\n",i);
    }
}
