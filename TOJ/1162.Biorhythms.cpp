#include <stdio.h>
int main()
{
    int p,e,i,d,t=0,k;
    while(scanf("%d%d%d%d",&p,&e,&i,&d)&&d>=0)
    {
        k=(5544*p+14421*e+1288*i-d+21252)%21252;
        printf("Case %d: the next triple peak occurs in %d days.\n",++t,k?k:21252);
    }
}
