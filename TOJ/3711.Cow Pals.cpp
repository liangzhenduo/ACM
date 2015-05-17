#include <stdio.h>
#include <math.h>
int sum[20464],res[20464],s;
int main()
{
    for(int i=6;i<18417;i++)
    {
        int t=1;
        double k=i;
        for(int j=2;j<=sqrt(k);j++)
            if(i%j==0)
                t+=i-j*j?j+i/j:j;
        sum[i]=t;
    }
    for(int i=6;i<18417;i++)
        if(i==sum[sum[i]]&&i-sum[i])
        {
            res[i]=sum[i];
            res[sum[i]]=i;
        }
    while(scanf("%d",&s)!=EOF)
        for(int i=s;;i++)
            if(res[i])
            {
                printf("%d %d\n",i,res[i]);
                break;
            }
}
