#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    long long a,b,s,m,n;
    while(cin >>a>>b>>s>>m>>n&&a+b+s+m+n)
        cout <<fixed<<setprecision(2)<<atan(b*n/double(a*m))*90/acos(0)<<" "<<sqrt(a*a*m*m+b*b*n*n)/s<<endl;
    return 0;
}
