#include <stdio.h>
#include <math.h>
using namespace std;
struct Point{
    double x,y;
}c,a,b;
double r;
double disP(Point &a,Point &b)
{
    return pow((a.x-b.x),2)+pow((a.y-b.y),2);
}
double disL(Point &a,Point &b,Point &c)
{
    double k=(a.y-b.y)/(a.x-b.x);
    return a.x-b.x?pow(fabs(k*c.x-c.y+a.y-k*a.x),2)/(k*k+1):a.x*b.x;
}
double cosA(Point &a,Point &b,Point &c)
{
    return (disP(a,c)+disP(b,c)-disP(a,b))/sqrt(4*disP(a,c)*disP(b,c));
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf",&c.x,&c.y,&r,&a.x,&a.y,&b.x,&b.y);
        if(disP(a,c)<=r*r&&disP(b,c)<=r*r)
            puts("All in");
        else if((disP(a,c)<r*r^disP(b,c)<r*r)||(disL(a,b,c)<r*r&&cosA(b,c,a)>0&&cosA(a,c,b)>0))
            puts("Part in");
        else
            puts("All out");
    }
}
