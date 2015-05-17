#include <stdio.h>
#include <math.h>
int main()
{
    int x[15],y[15],n,i,j,k,l,p1,p2,p3,flag;
    double s,area;
    char point[16];
    while(scanf("%d",&n)&&n)
    {
        for(i=0;i<n;i++)
        {
            getchar();
            scanf("%c%d%d",&point[i],&x[i],&y[i]);
        }
        for(i=0,area=0;i<n-2;i++)
            for(j=i+1;j<n-1;j++)
                for(k=j+1;k<n;k++)
                {
                    s=fabs(0.5*((y[k]-y[i])*(x[j]-x[i])-(y[j]-y[i])*(x[k]-x[i])));
                    for(l=0,flag=1;l<n;l++)
                        if(l!=i&&l!=j&&l!=k&&2*s==fabs((y[l]-y[i])*(x[j]-x[i])-(y[j]-y[i])*(x[l]-x[i]))+fabs((y[k]-y[i])*(x[l]-x[i])-(y[l]-y[i])*(x[k]-x[i]))+fabs((y[k]-y[l])*(x[j]-x[l])-(y[j]-y[l])*(x[k]-x[l])))
                            {flag=0;break;}
                    if(flag&&s>area)
                        area=s,p1=i,p2=j,p3=k;
                }
        printf("%c%c%c\n",point[p1],point[p2],point[p3]);
    }
}
