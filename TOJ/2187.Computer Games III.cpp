#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double a,b;
    while(cin >>a>>b&&a+b)
        cout <<fixed<<setprecision(3)<<(a-b)/(a+b)<<endl;
    return 0;
}
