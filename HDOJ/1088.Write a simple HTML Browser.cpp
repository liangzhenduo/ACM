#include <cstdio>
#include <cstring>
char word[10000][81];
int main(){
    int n=0,i,j;
    while(scanf("%s",word[n])!=EOF) n++;
    for(j=i=0;i<n;i++){
        if(strcmp(word[i],"<hr>")==0){
            if(j) puts("");
            puts("--------------------------------------------------------------------------------");
            j=0;
        }
        else if(strcmp(word[i],"<br>")==0){
            puts("");
            j=0;
        }
        else{
            if(!j) printf("%s",word[i]);
            else if(j+strlen(word[i])>=80) j=0,printf("\n%s",word[i]);
            else j++,printf(" %s",word[i]);
            j+=strlen(word[i]);
        }
    }
    puts("");
}