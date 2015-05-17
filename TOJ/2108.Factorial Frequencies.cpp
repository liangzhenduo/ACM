#include <stdio.h>
int main()
{
    int n,i,j,k;
    while(scanf("%d",&n)&&n)
    {
        int dig[782]={1},num[10]={0};
        for(i=2;i<=n;i++)
        {
            for(j=0;j<782;j++)
                dig[j]*=i;
            for(j=0;j<782;j++)
                if(dig[j]>=10)
                {
                    dig[j+1]+=dig[j]/10;
                    dig[j]%=10;
                }
        }
        for(i=781,k=0;i>=0;i--)
        {
            if(dig[i]) k++;
            if(k) num[dig[i]]++;
        }
        printf("%d! --\n   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",n,num[0],num[1],num[2],num[3],num[4],num[5],num[6],num[7],num[8],num[9]);
    }
}
