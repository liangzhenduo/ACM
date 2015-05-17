#include <iostream>
using namespace std;
int main()
{
    int t,n;
    cin >>t;
    while(t--)
    {
        cin >>n;
        const int m=n;
        int a[m],b[m];
        for(int i=0;i<n;i++)
            cin >>a[i];
        for(int i=0;i<n;i++)
            cin >>b[i];
        a[1]+=a[0];
        b[1]+=b[0];
        for(int i=2;i<n;i++)
        {
            if(a[i-1]>b[i-2])
                a[i]+=a[i-1];
            else
                a[i]+=b[i-2];
            if(b[i-1]>a[i-2])
                b[i]+=b[i-1];
            else
                b[i]+=a[i-2];
        }
        if(a[n-1]>b[n-1])
            cout <<a[n-1]<<endl;
        else
            cout <<b[n-1]<<endl;
    }
    return 0;
}
