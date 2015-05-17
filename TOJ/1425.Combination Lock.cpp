#include <stdio.h>
int main()
{
    int a,b,c,d;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)&&a+b+c+d)
        printf("%d\n",9*(120+(40-b+a)%40+(40-b+c)%40+(40-d+c)%40));
}
