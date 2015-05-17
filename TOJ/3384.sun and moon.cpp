#include <stdio.h>
int main()
{
    int n,p,q;
    while(scanf("%d%d%d",&n,&p,&q)!=EOF)
        printf("%s\n",n%(p+q)&&n%(p+q)<=p?"LOST":"WIN");
}
