#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
int main()
{
    int t;
    cin >>t;
    for(int i=1;i<=t;i++)
    {
        double data;
        string unit;
        cin >>data>>unit;
        if(unit=="kg")
            cout <<i<<" "<<setiosflags(ios::fixed)<<setprecision(4)<<2.2046*data<<" "<<"lb"<<endl;
        else if(unit=="lb")
            cout <<i<<" "<<setiosflags(ios::fixed)<<setprecision(4)<<0.4536*data<<" "<<"kg"<<endl;
        else if(unit=="l")
            cout <<i<<" "<<setiosflags(ios::fixed)<<setprecision(4)<<0.2642*data<<" "<<"g"<<endl;
        else if(unit=="g")
            cout <<i<<" "<<setiosflags(ios::fixed)<<setprecision(4)<<3.7854*data<<" "<<"l"<<endl;
    }
    return 0;
}
