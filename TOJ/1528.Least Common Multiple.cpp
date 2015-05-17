#include <iostream>
using namespace std;

    int gcd(int a,int b)
    {
        if(b==0)
            return a;
        else
            return gcd(b,a%b);
    }

int main()
{
    int t,n,num,lcm;
    cin >>t;
    while(t--)
    {
        cin >>n;
        lcm=1;
        while(n--)
        {
            cin >>num;
            lcm*=(num/gcd(lcm,num));
        }
        cout <<lcm<<endl;
    }
    return 0;
}
