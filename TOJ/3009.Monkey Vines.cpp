#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
    char bra[151];
    int t,i=0,j,k,m;
    scanf("%d",&t);getchar();
    while(i++<t){
        gets(bra);
        for(j=k=m=0;j<strlen(bra);j++){
            if(bra[j]=='[') k++;
            else if(bra[j]==']') k--;
            m=m<k?k:m;
        }
        printf("%d %d\n",i,int(pow(2,m)));
    }
}
