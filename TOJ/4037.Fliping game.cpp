#include <iostream>
using namespace std;
int main()
{
    int t,n,m,coin;
    cin >>t;
    while(t--)
    {
        cin >>n>>m;
        for(int i=0;i<n*m;i++)
            cin >>coin;
        cout <<(coin?"Alice":"Bob")<<endl;
    }
    return 0;
}
