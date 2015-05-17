#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int t,k,m,n;
    cin >>t;
    for(int i=0;i<t;i++)
    {
        double p=1,q=1;
        cin >>n>>m>>k;
        for(int j=0;j<k;j++)
        {
            p=p*m;
            q=q*n;
            m--;
            n--;
        }
        double possibility=p/q;
        cout <<setiosflags(ios::fixed)<<setprecision(4)<<possibility<<endl;
    }
    return 0;
}

