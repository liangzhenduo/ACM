#include <stdio.h>
#include <math.h>
int main()
{
    double exc[5][5],amo;
    int n,cou[11],k,i,j;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            scanf("%lf",&exc[i][j]);
    while(scanf("%d",&n)&&n)
    {
        for(i=0;i<n;i++)
            scanf("%d",&cou[i]);
        cou[i]=1;
        scanf("%lf",&amo);
        for(i=j=0;i<=n;amo=floor(amo*100+0.5)/100,j=cou[i++]-1)
            amo*=exc[j][cou[i]-1];
        printf("%.2lf\n",amo);
    }
}
