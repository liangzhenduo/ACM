#include <iostream>
using namespace std;
int main()
{
    int t,n;
    cin >>t;
    while(t--)
    {
        cin >>n;
        int pa=1,ma=0,k;
        for(int i=0;i<n+2;i++)
        {
            k=ma;
            ma+=pa;
            pa=k;
        }
        cout <<pa<<" "<<ma<<endl;
    }
    return 0;
}

