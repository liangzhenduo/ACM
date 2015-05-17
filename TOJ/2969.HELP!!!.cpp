#include <iostream>
using namespace std;
int main()
{
    long long n,a[51][51];
    for(int i=0;i<51;i++)
        a[i][0]=a[i][i]=1;
    for(int i=1;i<51;i++)
        for(int j=1;j<i;j++)
            a[i][j]=a[i-1][j]+a[i-1][j-1];
    while(cin >>n&&n>=0)
    {
        cout <<1;
        for(int i=1;i<=n;i++)
            cout <<" "<<a[n][i];
        cout <<endl;
    }
    return 0;
}
