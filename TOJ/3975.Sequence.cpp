#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int t,k;
    cin >>t;
    for(int i=1;i<=t;i++)
    {
        cin >>k;
        if(k==1)
            cout <<"Case "<<i<<": 0.60"<<endl;
        else if(k==2)
            cout <<"Case "<<i<<": 0.70"<<endl;
        else
        {
            double a=0.6,b=0.7,c;
            for(int j=2;j<k;j++)
            {
                c=0.5*a+0.6*b;
                a=b;
                b=c;
            }
            cout <<"Case "<<i<<": "<<setiosflags(ios::fixed)<<setprecision(2)<<c<<endl;
        }
    }
    return 0;
}
