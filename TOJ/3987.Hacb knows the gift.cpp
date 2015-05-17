#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        long long f;
        cin >>f;
        double y;
        if(f<0)
            y=-f;
        else
            y=f;
        long long x=pow(y,1.0/3),j;
        int k=0;
        for(j=x;j<=x+1;j++)
        {
            if(j*j*j==f&&f>=0)
            {
                cout <<j<<endl;
                k=1;
                break;
            }
            if(j*j*j==-f&&f<0)
            {
                cout <<-j<<endl;
                k=1;
                break;
            }
        }
        if(k==0)
            cout <<"Wrong Message!"<<endl;
        if(i!=n-1)
            cout <<endl;
    }
    return 0;
}
