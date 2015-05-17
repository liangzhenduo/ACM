#include <iostream>
using namespace std;
int main()
{
    int t,a,b,x,y;
    cin >>t;
    while(t--)
    {
        cin >>a>>b>>x>>y;
        if(x*x/(a*a)+y*y/(b*b)<1)
            cout <<"In ellipse"<<endl;
        else
            cout <<a*a*b*b<<endl;
    }
    return 0;
}
