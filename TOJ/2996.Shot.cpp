#include <stdio.h>
int main()
{
    double h,l,v;
    while(scanf("%lf%lf%lf",&h,&l,&v)&&h+l+v)
        printf("%.2lf\n",h+v*v/19.6-4.9*l*l/v/v);
}
