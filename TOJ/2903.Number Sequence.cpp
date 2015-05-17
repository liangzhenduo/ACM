#include <stdio.h>
#include <string.h>
int main()
{
    int n,i,j,k,num[9989];
    char str[5];
    for(i=1;i<9989;i++)
    {
        for(j=0,k=i;k;j++,k/=10);
        num[i]=j*i+num[i-1];
    }
    while(scanf("%d",&n)!=EOF)
    {
        memset(str,0,5);
        for(i=1;n>num[i];i++);
        k=n-num[i-1];
        for(j=0;i;j++,i/=10)
            str[j]=i%10+48;
        k=(k-1)%strlen(str)+1;
        printf("%c\n",str[strlen(str)-k]);
    }
}
