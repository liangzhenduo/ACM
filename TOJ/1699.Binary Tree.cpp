#include <stdio.h>
int main(){
    int t,i=0,a,b,l,r;
    scanf("%d",&t);
    while(i++<t){
        scanf("%d%d",&a,&b);
        l=r=0;
        while(a>1||b>1)
            if(a>b){
                l+=(a-1)/b;
                a-=(a-1)/b*b;
            }
            else{
                r+=(b-1)/a;
                b-=(b-1)/a*a;
            }
        printf("Scenario #%d:\n%d %d\n\n",i,l,r);
    }
}
