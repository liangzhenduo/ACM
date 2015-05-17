#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n,s,k;
    while(cin >>n)
    {
        k=1,s=0;
        while(n)
        {
            s+=(n&1);
            n/=2;
        }
        k=pow(2,s);
        cout <<k<<endl;
    }
    return 0;
}
