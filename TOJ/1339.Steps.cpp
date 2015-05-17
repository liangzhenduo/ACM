#include <stdio.h>
#include <math.h>
int main()
{
    int t,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",(int)(sqrt(y-x)*2-1e-8));
    }
}
