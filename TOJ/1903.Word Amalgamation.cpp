#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(const char *p,const char *q){
    return strcmp(p,q)>0?0:1;
}
int main(){
    int n,i,j,k;
    char word[100][20],tmp[20],*dic[100],*wor[100];
    for(n=0;scanf("%s",word[n])&&strcmp(word[n],"XXXXXX");n++);
    for(i=0;i<n;i++)
        dic[i]=word[i];
    sort(dic,dic+n,cmp);
    for(i=0;i<n;i++){
        wor[i]=(char*)malloc(strlen(dic[i])+1);
        strcpy(wor[i],dic[i]);
        sort(wor[i],wor[i]+strlen(wor[i]));
    }
    while(scanf("%s",tmp)&&strcmp(tmp,"XXXXXX")){
        sort(tmp,tmp+strlen(tmp));
        for(k=i=0;i<n;i++)
            if(!strcmp(tmp,wor[i])){
                puts(dic[i]);
                k++;
            }
        if(!k) puts("NOT A VALID WORD");
        puts("******");
    }
}
