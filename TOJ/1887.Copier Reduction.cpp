#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    double a,b,c,d,p,q;
    while(cin >>a>>b>>c>>d&&a+b+c+d)
    {
        p=max(c,d)/max(a,b);
        q=min(c,d)/min(a,b);
        if(p>1&&q>1)
            cout <<"100%"<<endl;
        else
            cout <<int(100*min(p,q))<<"%"<<endl;
    }
    return 0;
}
