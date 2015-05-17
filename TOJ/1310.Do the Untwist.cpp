#include <stdio.h>
#include <string.h>
int main()
{
    int k,n,plc[71],cic[71],i;
    char plt[71],cit[71];
    while(scanf("%d",&k)&&k)
    {
        scanf("%s",cit);
        n=strlen(cit);
        for(i=0;i<n;i++)
        {
            cic[i]=i+(cit[i]>96&&cit[i]<123?cit[i]-96:(cit[i]-46?0:27));
            while(cic[i]>=28)
                cic[i]-=28;
        }
        for(i=0;i<n;i++)
            plc[k*i%n]=cic[i];
        for(i=0;i<n;i++)
            plt[i]=plc[i]>0&&plc[i]<27?plc[i]+96:(plc[i]?46:95);
        plt[i]='\0';
        puts(plt);
    }
}
