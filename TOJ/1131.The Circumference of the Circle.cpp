#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	double x1,y1,x2,y2,x3,y3,a,b,c,r;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
	{
		a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
		c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
		r=a*b*c/sqrt((a+b+c)*(a+b-c)*(a-b+c)*(b+c-a));
        cout <<setiosflags(ios::fixed)<<setprecision(2)<<2*3.141592653589793*r<<endl;
	}
	return 0;
}
