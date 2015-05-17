#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long n;
    while(cin >>n&&n>=0)
    {
        for(int i=2;i<=(int)sqrt(n);i++)
            while(!(n%i))
            {
                cout <<"    "<<i<<endl;
                n/=i;
            }
        if(n>1)
            cout <<"    "<<n<<endl<<endl;
    }
    return 0;
}
