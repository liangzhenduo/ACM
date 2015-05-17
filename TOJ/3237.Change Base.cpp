#include <stdio.h>
#include <string.h>
int main()
{
    int t,b,k,i;
    char m[1001];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%s",&b,m);
        for(i=0,k=0;i<strlen(m);i++)
            k=(k*b+m[i]-48)%10007;
        printf("%d\n",k);
    }
}
