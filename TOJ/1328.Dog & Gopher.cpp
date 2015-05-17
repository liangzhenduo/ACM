#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int k=0;
    double x1,y1,x2,y2,x,y;
    cin >>x1>>y1>>x2>>y2;
    while(cin >>x>>y)
    {
        if(4*((x-x1)*(x-x1)+(y-y1)*(y-y1))<(x-x2)*(x-x2)+(y-y2)*(y-y2))
        {
            cout <<fixed<<setprecision(3)<<"The gopher can escape through the hole at ("<<x<<","<<y<<")."<<endl;
            k++;
            break;
        }
    }
    if(!k)
            cout <<"The gopher cannot escape."<<endl;
    return 0;
}
