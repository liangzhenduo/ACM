#include <stdio.h>
#include <string.h>
int main()
{
    char t[5],str[201];
    while(scanf("%s",t)!=EOF)
    {
        scanf("%s",str);
        int need[10]={0},num[10]={0},k=strlen(str),i;
        for(i=0;i<strlen(t);i++)
            need[t[i]-48]++;
        need[5]+=need[2],need[2]=0;
        need[6]+=need[9],need[9]=0;
        for(i=0;i<k;i++)
            num[str[i]-48]++;
        num[5]+=num[2],num[2]=0;
        num[6]+=num[9],num[9]=0;
        for(i=0;i<10;i++)
            k=need[i]&&num[i]/need[i]<k?k=num[i]/need[i]:k;
        printf("%d\n",k);
    }
}
