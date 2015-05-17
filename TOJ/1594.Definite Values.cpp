#include <stdio.h>
#include <string.h>
int main()
{
    int n,t=0,flag,rec[26];
    char v1,v2;
    while(scanf("%d",&n)&&n)
    {
        memset(rec,0,sizeof(rec));
        rec[0]=1;
        while(n--)
        {
            getchar();
            scanf("%c = %c",&v1,&v2);
            rec[v1-97]=rec[v2-97];
        }
        flag=0;
        printf("Program #%d\n",++t);
        for(int i=0;i<26;i++)
           if(rec[i])
             flag=1,printf("%c ",i+97);
        printf(flag?"\n\n":"none\n\n");
    }
}
