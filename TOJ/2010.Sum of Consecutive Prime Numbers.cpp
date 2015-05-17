#include <stdio.h>
#include <math.h>
int main()
{
    int n,k=1,num[10001]={0},pri[1230]={0,2},i,j,res;
    for(i=2;i<10001;i++)
        for(j=2;!num[i]&&j<=sqrt(i);j++)
            if(i%j==0)
                num[i]=1;
    for(i=3;i<10001;i++)
        if(!num[i])
            pri[++k]=pri[k-1]+i;
    while(scanf("%d",&n)&&n)
    {
        for(i=1,res=0;i<1230;i++)
            for(j=i,k=1;k&&j<1230;j++)
                pri[j]-pri[i-1]>n?k--:(pri[j]-pri[i-1]<n?:res++);
        printf("%d\n",res);
    }
}
