#include <iostream>
using namespace std;
int main()
{
    int f0,f1,f2;
    int a,b,c;
    while(cin >>f0>>f1>>f2)
    {
        c=f0;
        a=(f2-2*f1+c)/2;
        b=f1-a-c;
        cout <<9*a+3*b+c<<" "<<16*a+4*b+c<<" "<<25*a+5*b+c<<endl;
    }
    return 0;
}

