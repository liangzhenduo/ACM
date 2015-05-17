#include <stdio.h>
#include <math.h>
int main()
{
    int r[16],g[16],b[16],r1,g1,b1,r2,g2,b2;
    for(int i=0;i<16;i++)
        scanf("%d%d%d",&r[i],&g[i],&b[i]);
    while(scanf("%d%d%d",&r1,&g1,&b1)&&b1>=0)
    {
        double D=442,d;
        for(int i=0;i<16;i++)
        {
            d=sqrt((r[i]-r1)*(r[i]-r1)+(g[i]-g1)*(g[i]-g1)+(b[i]-b1)*(b[i]-b1));
            if(d<D)
                D=d,r2=r[i],g2=g[i],b2=b[i];
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n",r1,g1,b1,r2,g2,b2);
    }
}
