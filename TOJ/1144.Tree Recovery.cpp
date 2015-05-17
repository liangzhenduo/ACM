#include <cstdio>
#include <cstring>
char dlr[27],ldr[27];
void lrd(int a,int b){
    if(a==b) return;
    int i,j,k=-1;
    for(i=0;i<strlen(dlr)&&k<0;i++)
        for(j=a;k<0&&j<b;j++)
            if(ldr[j]==dlr[i])
                k=j;
    lrd(a,k);
    lrd(k+1,b);
    printf("%c",ldr[k]);
}
int main(){
    while(scanf("%s%s",dlr,ldr)!=EOF){
        lrd(0,strlen(ldr));
        puts("");
    }
}
