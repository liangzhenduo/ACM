#include <iostream>
using namespace std;
int main()
{
    int t,x1,x2,y1,y2,x,y,r;
    cin >>t;
    while(t--)
    {
        cin >>x1>>y1>>x2>>y2>>x>>y>>r;
        if(x-r>=x1&&x+r<=x2&&y-r>=y1&&y+r<=y2)
            cout <<"Just do it"<<endl;
        else
            cout <<"Don't get close to it"<<endl;
    }
    return 0;
}

