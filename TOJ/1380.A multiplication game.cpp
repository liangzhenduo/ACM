#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    long long p,n,t;
    while(cin >>n)
    {
        t=0;
        p=1;
        while(p<n)
        {
            t++;
            if(t%2)
                p*=9;
            else
                p*=2;
        }
        if(t%2)
            cout <<"Stan wins."<<endl;
        else
            cout <<"Ollie wins."<<endl;
    }
    return 0;
}
