#include <cstdio>
#include <cstring>
#include <cmath>
const double cst=(sqrt(5.0)+1)/2;
int main(){
	int n,i,j,k;
	int fib[15000]={0,1};
	for(i=2;i<40;i++)
		fib[i]=(fib[i-1]+fib[i-2]);
	for(i=40;i<15000;i++)
		fib[i]=(fib[i-1]+fib[i-2])%10000;
	while(scanf("%d",&n)!=EOF){
		if(n<40) printf("%d\n",fib[n]);
		else{
			double f=-0.5*(log10(5.0))+n*log10(cst);
            f-=(int)f;
            f=pow(10,f); 
            while(f<1000) f*=10;
            printf("%d...%.4d\n",int(f),fib[n%15000]%10000);
		}
	}
}