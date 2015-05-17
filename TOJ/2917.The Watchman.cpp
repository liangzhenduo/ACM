#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    double area;
    while(cin >>area&&area>0)
        cout <<fixed<<setprecision(2)<<sqrt(2*area)<<endl;
    return 0;
}
