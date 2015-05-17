#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long n,m,k;
    while(cin >>n&&n)
    {
        k=0;
        for(long long i=0;i<n;i++)
        {
            cin >>m;
            k+=(long long)pow(2.0,i)*m;
        }
        cout <<k<<endl;
    }
    return 0;
}

