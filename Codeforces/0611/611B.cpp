#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
long long num[2050];
int main(){
	int i,j,m=0;
	long long k,l;
	for(i=1;i<64;i++){
		k=(1LL<<i)-1;
		for(j=i-2;j>=0;j--){
			l=1LL<<j;
			num[m++]=k-l;
		}
	}
	long long a,b;
	while(cin>>a>>b){
		b++;
		for(i=0;;i++){
			if(num[i]>=a)
				break;
		}
		for(j=0;;j++){
			if(num[j]>=b)
				break;
		}
		printf("%d\n",j-i);
	}
} 