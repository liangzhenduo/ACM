#include <iostream>
using namespace std;
int main()
{
    int t,n,m,b1,b2;
    cin >>t;
    while(t--)
    {
        cin >>n>>m>>b1>>b2;
        int x=n-b1,y=m-b2;
        while(y)
        {
            int z=y;
            y=x%y;
            x=z;
        }
        cout <<x<<endl;
    }
    return 0;
}
