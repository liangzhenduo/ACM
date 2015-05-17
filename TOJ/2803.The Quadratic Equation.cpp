#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    double a,b,c;
    cin >>n;
    while(n--)
    {
        cin >>a>>b>>c;
        if(b*b-4*a*c<0)
            cout <<"No solution!"<<endl;
        else if(b*b-4*a*c==0)
            cout <<fixed<<setprecision(3)<<-b/2*a<<endl;
        else
            cout <<fixed<<setprecision(3)<<(-b-sqrt(b*b-4*a*c))/(2*a)<<" "<<(-b+sqrt(b*b-4*a*c))/(2*a)<<endl;
    }
    return 0;
}
