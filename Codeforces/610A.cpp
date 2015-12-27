#include <cstdio>
#include <cstring>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n%2){
			puts("0");
			continue;
		}
		else{
			n/=2;
			if(n%2)
				printf("%d\n",n/2);
			else
				printf("%d\n",n/2-1);
		}
	}
}