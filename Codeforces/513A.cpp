#include <stdio.h>
int main(){
    int n1,n2,k1,k2;
    while(scanf("%d%d%d%d",&n1,&n2,&k1,&k2)!=EOF){
        if(n1>n2) puts("First");
        else puts("Second");
    }
}
