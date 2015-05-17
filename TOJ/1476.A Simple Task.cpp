#include <iostream>
using namespace std;
int main()
{
    int m;
    cin >>m;
    for (int i=0;i<m;i++)
    {
        int n,o,x;
        int p=0;
        cin>>n;
        x=n%2;
        while (x!=1)
        {
            p=p+1;
            n=n/2;
            x=n%2;
        }
        o=n;
        cout <<o<<" "<<p<<endl;
    }
    return 0;
}
