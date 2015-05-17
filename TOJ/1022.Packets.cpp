#include <iostream>
using namespace std;
int main()
{
	int a,b,c,d,e,f,res;
	while(cin >>a>>b>>c>>d>>e>>f&&a+b+c+d+e+f)
	{
		res=f+e+d+(c+3)/4;
		int B=5*d+((c%4)?(7-2*(c%4)):0);
		if(b>B)
			res+=(b-B+8)/9;
		int A=36*res-36*f-25*e-16*d-9*c-4*b;
		if(a>A)
			res+=(a-A+35)/36;
		cout <<res<<endl;
	}
	return 0;
}
