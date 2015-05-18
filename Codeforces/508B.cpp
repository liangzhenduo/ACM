#include <stdio.h>
#include <string.h>
int main(){
    char num[100001],tmp,k;
    int i,j;
    while(scanf("%s",num)!=EOF){
        for(k=num[strlen(num)-1],i=0,j=strlen(num);i<strlen(num);i++)
            if(num[i]<k&&num[i]%2==0){
                tmp=num[i];
                num[i]=num[strlen(num)-1];
                num[strlen(num)-1]=tmp;
                j=i;
                break;
            }
        if(j==strlen(num)){
            for(i=strlen(num)-2;i>=0;i--)
                if(num[i]%2==0){
                    tmp=num[i];
                    num[i]=num[strlen(num)-1];
                    num[strlen(num)-1]=tmp;
                    j=i;
                    break;
                }
        }
        if(j-strlen(num))
            printf("%s\n",num);
        else
            puts("-1");
    }
}
