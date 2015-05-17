#include <stdio.h>
int main()
{
    int cas,n,m,s,t,a,b,c;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d%d%d",&n,&m,&s,&t);
        int dis[n][n],i,j,k;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                dis[i][j]=0xfffffff;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            dis[a-1][b-1]=dis[b-1][a-1]=c;
        }
        for(k=0;k<n;k++)
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    dis[i][j]=dis[i][j]>dis[i][k]+dis[k][j]?dis[i][k]+dis[k][j]:dis[i][j];
        printf("%d\n",dis[s-1][t-1]-0xfffffff?dis[s-1][t-1]:-1);
    }
}
