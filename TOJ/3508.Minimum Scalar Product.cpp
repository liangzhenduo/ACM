#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t,i=0,n;
    cin >>t;
    while(i<t)
    {
        i++;
        cin >>n;
        const int m=n;
        long long x[m],y[m],sum=0;
        for(int j=0;j<n;j++)
            cin >>x[j];
        sort(x,x+n);
        for(int j=0;j<n;j++)
            cin >>y[j];
        sort(y,y+n);
        for(int j=0;j<n;j++)
            sum+=x[j]*y[n-1-j];
        cout <<"Case #"<<i<<": "<<sum<<endl;
    }
    return 0;
}
