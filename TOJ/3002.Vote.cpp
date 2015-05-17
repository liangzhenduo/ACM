#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    while(cin >>n&&n)
    {
        int m[n],k=0;
        for(int i=0;i<n;i++)
            cin >>m[i];
        sort(m,m+n);
        for(int j=0;j<n/2+1;j++)
            k+=(m[j]/2+1);
        cout <<k<<endl;
    }
    return 0;
}
