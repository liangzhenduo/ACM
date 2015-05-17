#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        int m;
        cin >>m;
        int strip[10000];
        for(int j=0;j<m;j++)
            cin >>strip[j];
        int appliance=1;
        for(int k=0;k<m;k++)
            appliance=appliance+strip[k];
        cout <<appliance-m<<endl;
    }
    return 0;
}
