#include <iostream>
using namespace std;
int main()
{
    int m;
    while(cin >>m)
    {
        if(m%2==1)
        {
            int n=(m-1)/2;
            cout <<m<<" "<<2*n*n+2*n<<" "<<2*n*n+2*n+1<<endl;
        }
        else
        {
            int n=m/2;
            cout <<m<<" "<<n*n-1<<" "<<n*n+1<<endl;
        }
    }
    return 0;
}
