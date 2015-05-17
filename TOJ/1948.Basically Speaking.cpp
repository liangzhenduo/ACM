#include <stdio.h>
#include <string.h>
#include <algorithm>
int main()
{
    char num1[28],num2[7];
    int bas1,bas2,i,j,k;
    while(scanf("%s%d%d",num1,&bas1,&bas2)==3)
    {
        for(i=strlen(num1)-1,j=1,k=0;i>=0;i--,j*=bas1)
            k+=(num1[i]<58?num1[i]-48:num1[i]-55)*j;
        for(i=0,memset(num2,0,7);k;i++,k/=bas2)
            num2[i]=k%bas2+(k%bas2<10?48:55);
        std::reverse(num2,num2+i);
        printf(i>7?"  ERROR\n":"%7.7s\n",num2);
    }
}
