#include <iostream>
using namespace std;
int main()
{
    long long n,m,k,o,i;
    while(cin >>n>>m&&n+m)
    {
        k=1,o=n+m;
        n=n>m?m:n;
        for(i=1;i<=n;i++)
        {
            k=k*o/i;
            o--;
        }
        cout <<k<<endl;
    }
    return 0;
}
