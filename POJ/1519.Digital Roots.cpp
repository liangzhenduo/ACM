#include <cstdio>
#include <cstring>
int main(){
    char num[1024];
    while(scanf("%s",num)&&num[0]!=48){
        int n=0,k,i;
        for(i=0;i<strlen(num);i++)
            n+=num[i]-48;
        while(n>9){
            k=0;
            while(n>0){
                k+=n%10;
                n/=10;
            }
            n=k;
        }
        printf("%d\n",n);
    }
}
