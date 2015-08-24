#include <cstdio>
int main(){
    int n,m,x,w,y;
    while(~scanf("%d%d%d%d",&x,&y,&w,&n)){
        m=x/w+1;
        printf("%d\n",(n-1)/m*(x+y)+(n-1)%m*w);
    }
}