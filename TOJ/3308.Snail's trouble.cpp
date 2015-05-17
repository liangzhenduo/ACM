#include <iostream>
using namespace std;
int main()
{
    int k;
    while(cin >>k)
    {
        long long t=1,len=0,s=100;
        double l=k*1.0,r=100;
        while(s-l>len)
        {
            r=s-l;
            s+=100;
            l=l*s/(s-100)+k;
            t++;
        }
        cout <<t<<endl;
    }
    return 0;
}
