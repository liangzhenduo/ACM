#include <stdio.h>
#include <math.h>
int main()
{
	double x1,x2,y1,y2,r1,r2,c,p;
	while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&x2,&y2,&r2)==6)
	{
		c=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		if(c>=r1+r2)
		    printf("0.000\n");
        else if(c<=fabs(r2-r1))
            printf("%.3lf\n",r1<r2?r1*r1*acos(-1):r2*r2*acos(-1));
		else
		{
            p=(r1+r2+c)/2;
            printf("%.3lf\n",r1*r1*acos((r1*r1+c*c-r2*r2)/2/r1/c)+r2*r2*acos((r2*r2+c*c-r1*r1)/2/r2/c)-2*sqrt(p*(p-r1)*(p-r2)*(p-c)));
		}
	}
}
