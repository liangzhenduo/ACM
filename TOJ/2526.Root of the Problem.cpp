#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double b,n;
    while(cin >>b>>n&&b!=0)
    {
        int i=pow(b,1/n);
        if(b-pow(i,n)<=pow(i+1,n)-b)
            cout <<i<<endl;
        else
            cout <<i+1<<endl;
    }
    return 0;
}
