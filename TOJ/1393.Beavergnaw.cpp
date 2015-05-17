#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    const double PI=acos(-1);
    double D,d,V;
    while(cin >>D>>V&&D+V)
        cout <<fixed<<setprecision(3)<<pow(D*D*D-6*V/PI,1.0/3)<<endl;
    return 0;
}
