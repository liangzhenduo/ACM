#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double money,k=0;
    int t=12;
    while(t--)
    {
        cin >>money;
        k+=money;
    }
    cout <<"$"<<fixed<<setprecision(2)<<k/12<<endl;
    return 0;
}
