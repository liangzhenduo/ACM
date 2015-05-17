#include <iostream>
using namespace std;
int main()
{
    int n,k;
    long long m;
    while(cin >>n>>k&&n+k)
    {
        m=1;
        k=k<(n-k)?k:n-k;
        for(int i=1;i<=k;i++)
            m=(m*(n-k+i))/i;
        cout <<m<<endl;
    }
    return 0;
}
