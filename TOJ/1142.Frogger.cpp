#include <stdio.h>
#include <math.h>
#include <algorithm>
int main()
{
    int n,i,j,k,t=0;
    double x[1000],y[1000];
    while(scanf("%d",&n)&&n)
    {
        for(i=0;i<n;i++)
            scanf("%lf%lf",&x[i],&y[i]);
        double dis[n][n];
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                dis[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        for(k=0;k<n;k++)
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    dis[i][j]=std::min(dis[i][j],std::max(dis[i][k],dis[k][j]));
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",++t,dis[0][1]);
    }
}
