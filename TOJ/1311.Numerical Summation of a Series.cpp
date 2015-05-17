#include <stdio.h>
int main()
{
    double x,psix,i;
    for(x=0;x<2;x+=0.001)
    {
        for(i=1,psix=0;i<10000;i++)
            psix+=1/(i*(i+1)*(i+x));
        printf("%5.3lf %16.12lf\n",x,psix*(1-x)+(1-x)/(200000000)+1);
    }
}
