#include <iostream>
using namespace std;
int main()
{
    int r,w,l,t=0;
    while(cin >>r&&r!=0)
    {
        t++;
        cin >>w>>l;
        if(4*r*r<w*w+l*l)
            cout <<"Pizza "<<t<<" does not fit on the table."<<endl;
        else
            cout <<"Pizza "<<t<<" fits on the table."<<endl;
    }
    return 0;
}

