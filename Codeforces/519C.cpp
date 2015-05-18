#include <stdio.h>
int main(){
    int n,x;
    while(scanf("%d%d",&x,&n)!=EOF){
        int k=0;
        while(n>0&&x>0&&n+x>=3){
            if(n>x)
                n-=2,x--;
            else
                n--,x-=2;
            k++;
        }
        printf("%d\n",k);
    }
}
