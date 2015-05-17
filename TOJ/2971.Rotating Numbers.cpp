#include <stdio.h>
#include <string.h>
#include <algorithm>
int main()
{
    char m[256];
    int n;
    while(scanf("%s%d",m,&n)!=EOF)
    {
        int l=strlen(m),i,j;
        for(i=0,j=0;i<l;i++)
            if(m[i]-48)
                j++;
        n=n<l?n:(n-l)%j+l;
        std::reverse(m,m+l);
        for(i=0,j=l;i<n;i++)
            if(m[i]-48)
                m[j++]=m[i];
        for(j--;j>=n;j--)
            printf("%c",m[j]);
        printf("\n");
    }
}
