#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int t=0,a,b,c;
    while(cin >>a>>b>>c&&a+b+c)
    {
        t++;
        cout <<"Triangle #"<<t<<endl;
        if(c>0&&(a>c||b>c))
            cout <<"Impossible."<<endl;
        else if(a==-1)
            cout <<fixed<<setprecision(3)<<"a = "<<sqrt(c*c-b*b)<<endl;
        else if(b==-1)
            cout <<fixed<<setprecision(3)<<"b = "<<sqrt(c*c-a*a)<<endl;
        else if(c==-1)
            cout <<fixed<<setprecision(3)<<"c = "<<sqrt(a*a+b*b)<<endl;
        cout <<endl;
    }
    return 0;
}
