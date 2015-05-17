#include <stdio.h>
#include <math.h>
int main()
{
    int t;
    double D,d,s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf",&D,&d,&s);
        printf("%d\n",int(acos(-1)/asin((s+d)/(D-d))));
    }
}
