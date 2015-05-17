#include <stdio.h>
int main()
{
    int x,y,z,i;
    while(scanf("%de%d",&x,&z)&&x+z)
    {
        for(i=0,y=1;i<z;i++)
            x*=10;
        while(y<x)
        {
            x-=y;
            y*=2;
        }
        printf("%d\n",2*x-1);
    }
 }
