#include <stdio.h>
#include <math.h>
double f(int k)
{
    return 2*sqrt(1+1.0/k)+log(fabs((sqrt(1+1.0/k)-1)/(sqrt(1+1.0/k)+1)));
}
int main()
{
    int s,t;
    while(scanf("%d%d",&s,&t)!=EOF)
        printf("%.2lf\n",f(s)-f(t));
}
