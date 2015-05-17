#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double s,t;
    cin >>s;
    while(cin >>t)
    {
        if(t==999)
        {
            cout <<"End of Output"<<endl;
            break;
        }
        cout <<setiosflags(ios::fixed)<<setprecision(2)<<t-s<<endl;
        s=t;
    }
    return 0;
}

