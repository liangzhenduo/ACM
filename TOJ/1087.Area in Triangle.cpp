#include <stdio.h>
#include <math.h>
int main()
{
    double a,b,c,l,p,s,r;
    int x=0;
    while(scanf("%lf%lf%lf%lf",&a,&b,&c,&l)&&l)
    {
        printf("Case %d: ",++x);
        p=(a+b+c)/2,s=sqrt(p*(p-a)*(p-b)*(p-c));
        if(l>=a+b+c)
            printf("%.2lf\n",s);
        else if(l<=acos(-1)*s*2/p)
            printf("%.2lf\n",l*l/acos(-1)/4);
        else
        {
            r=s/p*(2*p-l)/(2*p-2*acos(-1)*s/p);
            printf("%.2lf\n",s-p*p*r*r/s+acos(-1)*r*r);
        }
    }
}
