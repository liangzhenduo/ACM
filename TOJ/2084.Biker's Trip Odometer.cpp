#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double PI=acos(-1.0);
int main()
{
    double d,r,t;
    int k=0;
    while(cin >>d>>r>>t&&r)
    {
        k++;
        cout <<"Trip #"<<k<<": "<<fixed<<setprecision(2)<<PI*d*r/63360<<" "<<PI*d*r/(17.6*t)<<endl;
    }
    return 0;
}
