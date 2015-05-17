#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    const double Pi=acos(-1.0);
    double r;
    while(cin >>r)
        cout <<fixed<<setprecision(6)<<r*r*Pi<<endl<<r*r*2<<endl;
    return 0;
}

