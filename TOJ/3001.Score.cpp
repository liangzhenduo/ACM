#include <iostream>
using namespace std;

    long long gcd(long long x,long long y)
    {
        if(!y)
            return x;
        else
            return gcd(y,x%y);
    }

int main()
{
    long long x,y,t;
    while(cin >>x>>y&&x+y)
    {
        if(x<y)
        {
            t=x;
            x=y;
            y=t;
        }
        if(gcd(x,y)==1)
            cout <<x*y-(x+y)<<endl;
        else
            cout <<"Inf"<<endl;
    }
    return 0;
}
