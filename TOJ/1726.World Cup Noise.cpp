#include <iostream>
using namespace std;
int main()
{
    int fib[45],k=0,t,n;
    fib[0]=0;
    fib[1]=2;
    fib[2]=3;
    for(int i=3;i<46;i++)
        fib[i]=fib[i-1]+fib[i-2];
    cin >>t;
    for(int i=1;i<=t;i++)
    {
        cin >>n;
        cout <<"Scenario #"<<i<<":"<<endl<<fib[n]<<endl<<endl;
    }
    return 0;
}

