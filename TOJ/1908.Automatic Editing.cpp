#include <stdio.h>
#include <string.h>
int main()
{
    int t,i;
    char fin[10][81],rep[10][81],tex[256],*beg,*end,tmp[256];
    while(scanf("%d",&t)&&t)
    {
        getchar();
        for(i=0;i<t;i++)
            gets(fin[i]),gets(rep[i]);
        gets(tex);
        for(i=0;i<t;i++)
            while(beg=strstr(tex,fin[i]))
            {
                end=beg+strlen(fin[i]);
                strcpy(tmp,rep[i]);
                strcat(tmp,end);
                strcpy(beg,tmp);
            }
        puts(tex);
    }
}
