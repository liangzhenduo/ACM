#include <stdio.h>
#include <string.h>
int main(){
    char pan[101];
    int len,cha[26],i,j;
    while(scanf("%d",&len)!=EOF){
        scanf("%s",pan);
        memset(cha,0,sizeof(cha));
        for(i=0;i<len;i++){
            if(pan[i]<91) cha[pan[i]-65]++;
            else cha[pan[i]-97]++;
        }
        for(i=0,j=1;i<26;i++)
            if(!cha[i]){
                j=0;
                break;
            }
        puts(j?"YES":"NO");
    }
}
