#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    double vs,r,c,w,vr;
    int t;
    while(cin >>vs>>r>>c>>t)
    {
        while(t--)
        {
            cin >>w;
            cout <<fixed<<setprecision(3)<<c*r*w*vs/sqrt(c*c*r*r*w*w+1)<<endl;
        }
    }
    return 0;
}
