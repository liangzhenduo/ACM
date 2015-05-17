#include <stdio.h>
#include <string.h>
int main()
{
    int n,t=0,i,j;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        int r1[26]={0},r2[26]={0},k=0;
        char w1[45],w2[45];
        gets(w1);
        for(i=0;i<strlen(w1);i++)
            r1[w1[i]-97]++;
        gets(w2);
        for(i=0;i<strlen(w2);i++)
            r2[w2[i]-97]++;
        for(j=0;j<26;j++)
            k+=r1[j]-r2[j]>0?r1[j]-r2[j]:r2[j]-r1[j];
        printf("Case #%d:  %d\n",++t,k);
    }
}
