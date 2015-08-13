#include <cstdio>
#include <cstring>
char c[25];
int num[7];
bool dfs(int sum){  
    if(sum>31) return 0;  
    for(int i=1;i<7;i++){  
        if(num[i]&&sum+i<=31){  
            num[i]--;  
            if(dfs(sum+i)==0){  
                num[i]++;  
                return 1;  
            }  
            num[i]++;  
        }  
    }  
    return 0;  
}  
int main(){
	int i,sum;
	while(scanf("%s",c)!=EOF){
		printf("%s ",c);
		for(i=1;i<7;i++) num[i]=4;
		for(sum=i=0;i<strlen(c);i++){
			sum+=c[i]-48;
			num[c[i]-48]--;
		}
		if(dfs(sum)) puts(i%2?"B":"A");
		else puts(i%2?"A":"B");
	}
}