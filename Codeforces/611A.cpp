#include <cstdio>
#include <cstring>
int main(){
	int n;
	char buf[6];
	while(scanf("%d of %s",&n,buf)!=EOF){
		if(buf[0]=='w'){
			if(n==5||n==6)
				puts("53");
			else puts("52");
		}
		else{
			if(n==31)
				puts("7");
			else if(n==30)
				puts("11");
			else
				puts("12");
		}
	}
} 