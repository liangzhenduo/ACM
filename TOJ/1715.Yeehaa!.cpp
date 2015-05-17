#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int t,n;
    double R,r;
    cin >>t;
    for(int i=1;i<=t;i++)
    {
        cin >>R>>n;
        r=R*sin(acos(-1.0)/n)/(1+sin(acos(-1.0)/n));
        cout <<"Scenario #"<<i<<":"<<endl<<setiosflags(ios::fixed)<<setprecision(3)<<r<<endl<<endl;
    }
    return 0;
}

