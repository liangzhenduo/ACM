#include <iostream>
using namespace std;
int main()
{
    long long x,y;
    while(cin >>x>>y)
    {
        long long z,a=x,b=y,m=x/y+1,n;
        while(b)
        {
            z=b;
            b=a%b;
            a=z;
        }
        n=y/a;
        cout <<n<<endl;
    }
    return 0;
}
