#include <stdio.h>
int main()
{
    char pos[3][14]={"Wide Receiver","Lineman","Quarterback"};
    double spe,speed[3]={4.5,6,5};
    int wei,str,weight[3]={150,300,200},strength[3]={200,500,300},i,flag;
    while(scanf("%lf%d%d",&spe,&wei,&str)&&spe+wei+str)
    {
        for(i=0,flag=1;i<3;i++)
            if(speed[i]>=spe&&weight[i]<=wei&&strength[i]<=str)
                printf("%s ",pos[i]),flag=0;
        if(flag)
            printf("No positions");
        printf("\n");
    }
}
