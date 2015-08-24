#include <cstdio>
#include <cstring>
int main(){
    int t,i,j,k;
    char str[10005],c;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        j=strlen(str);
        c=str[0];
        for(k=i=1;i<=j;i++)
            if(i<j&&str[i]==c) k++;
            else{
                if(k>1)
                    printf("%d",k);
                printf("%c",c);
                c=str[i];
                k=1;
            }
        puts("");
    }
}