#include <stdio.h>
#include <string.h>
int main(){
    char s[13],t[13];
    memset(s,0,sizeof(s));
    memset(t,0,sizeof(t));
    int i,j,k,l;
    while(scanf("%s",s)!=EOF){
        l=strlen(s);
        k=j=0;
        for(i=0;i<l;i++)
            t[i]=s[l-i-1];
        s[i+2]=t[i]=t[i+1]='\0';
        for(i=0;i<=l/2;i++){
            if(!k){
                if(s[i]==s[l-1-i]){
                    s[l-i]=s[i];
                }
                else{
                    s[l-i]=s[i];
                    k++;
                }
            }
            else if(s[i]!=s[l-i]){
                k=-1;
                break;
            }
        }
        if(k==-1)
            for(i=0;i<=l/2;i++){
                if(!j){
                if(t[i]==t[l-1-i]){
                    t[l-i]=t[i];
                }
                else{
                    t[l-i]=t[i];
                    j++;
                }
            }
            else if(t[i]!=t[l-i]){
                j=-1;
                break;
            }
        }
        if(k!=-1)
            printf("%s\n",s);
        else if(j!=-1)
            printf("%s\n",t);
        else
            puts("NA");
        memset(s,0,sizeof(s));
        memset(t,0,sizeof(t));
    }
}
