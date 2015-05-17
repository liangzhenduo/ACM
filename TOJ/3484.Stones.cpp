#include <iostream>
using namespace std;
int main()
{
    int t,n;
    cin >>t;
    while(t--)
    {
        int k=0,sum=0;
        cin >>n;
        const int m=n;
        int stone[m];
        while(n--)
        {
            cin >>stone[n-1];
            if(stone[n-1]>k)
                k=stone[n-1];
            sum+=stone[n-1];
        }
        cout <<sum-k<<endl;
    }
    return 0;
}
