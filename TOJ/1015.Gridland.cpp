#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int s;
    cin >>s;
    for(int i=1;i<=s;i++)
    {
        int m,n;
        cin >>m>>n;
        if(m%2==0||n%2==0)
            cout <<"Scenario #"<<i<<":"<<endl<<setiosflags(ios::fixed)<<setprecision(2)<<1.0*m*n<<endl<<endl;
        else
            cout <<"Scenario #"<<i<<":"<<endl<<setiosflags(ios::fixed)<<setprecision(2)<<m*n+0.41<<endl<<endl;
    }
    return 0;
}

