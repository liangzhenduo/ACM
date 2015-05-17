#include <iostream>
using namespace std;
int main()
{
    int t,n;
    cin >>t;
    for(int i=1;i<=t;i++)
    {
        cin >>n;
        if(n!=1&&n!=2)
            n=2*n-4;
        cout <<"Case "<<i<<": "<<n<<endl;
    }
    return 0;
}
