#include <iostream>
using namespace std;
int main()
{
    long long t,n,m;
    cin >>t;
    for(int i=1;i<=t;i++)
    {
        cin >>n>>m;
        cout <<"Scenario #"<<i<<":"<<endl<<(m-n+1)*(m+n)/2<<endl<<endl;
    }
    return 0;
}

