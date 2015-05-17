#include <iostream>
using namespace std;
int main()
{
    long long t,n,k;
    cin >>t;
    while(t--)
    {
        cin >>n;
        if(n==2)
            k=1;
        else if(n%2)
            k=(n/2)*(n/2+1);
        else if(n%4==0)
            k=n*n/4-1;
        else
            k=n*n/4-4;
        cout <<k<<endl;
    }
    return 0;
}
