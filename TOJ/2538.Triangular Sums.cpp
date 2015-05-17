#include <iostream>
using namespace std;
int main()
{
    int m,n;
    cin >>n;
    for(int i=1;i<=n;i++)
    {
        cin >>m;
        int t=1,k=0;
        for(int j=1;j<=m;j++)
        {
            t+=j+1;
            k+=t*j;
        }
        cout <<i<<" "<<m<<" "<<k<<endl;
    }
    return 0;
}

