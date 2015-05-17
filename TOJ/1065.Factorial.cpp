#include <iostream>
using namespace std;
int main()
{
    int t,n;
    cin >>t;
    for(int i=0;i<t;i++)
    {
        int k=0;
        cin >>n;
        for(int j=5;j<=n;j*=5)
            k+=n/j;
        cout <<k<<endl;
    }
    return 0;
}

