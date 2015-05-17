#include <stdio.h>
#include <math.h>
int num[1299710]={0};
int main()
{
    int k,i,j,l;
    for(i=2;i<1299710;i++)
        for(j=2;j<=sqrt(i);j++)
            if(i%j==0)
            {
                num[i]=1;
                break;
            }
    while(scanf("%d",&k)&&k)
    {
        if(!num[k])
            puts("0");
        else
        {
            for(i=k,l=0;num[i];i--,l++);
            for(i=k;num[i];i++,l++);
            printf("%d\n",l);
        }
    }
}
