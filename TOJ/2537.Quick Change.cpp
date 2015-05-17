#include <iostream>
using namespace std;
int main()
{
    int t,n;
    cin >>t;
    for(int i=1;i<=t;i++)
    {
        cin >>n;
        int Q=0,D=0,N=0,P=0;
        while(n>=25)
        {
            n-=25;
            Q++;
        }
        while(n>=10)
        {
            n-=10;
            D++;
        }
        while(n>=5)
        {
            n-=5;
            N++;
        }
        P=n;
        cout <<i<<" "<<Q<<" QUARTER(S), "<<D<<" DIME(S), "<<N<<" NICKEL(S), "<<P<<" PENNY(S)"<<endl;
    }
    return 0;
}

