#include <iostream>
using namespace std;
int main()
{
    int t,p,l,r,h;
    cin >>t;
    while(t--)
    {
        char name[4][8];
        cin >>name[0]>>p>>name[1]>>l>>name[2]>>r>>name[3]>>h;
        if(p<l&&p<r&&p<h)
            cout <<"Poor "<<name[0]<<endl;
        else if(l<p&&l<r&&l<h)
            cout <<"Poor "<<name[1]<<endl;
        else if(r<p&&r<l&&r<h)
            cout <<"Poor "<<name[2]<<endl;
        else if(h<p&&h<l&&h<r)
            cout <<"Poor "<<name[3]<<endl;
    }
    return 0;
}

