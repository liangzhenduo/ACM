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
        long long num[m],maximum=-9223372036854775807,minimum=9223372036854775807;
        for(int i=0;i<n;i++)
        {
            cin >>num[i];
            if(num[i]>maximum)
                maximum=num[i];
            if(num[i]<minimum)
                minimum=num[i];
        }
        cout <<maximum-minimum<<endl;
    }
    return 0;
}
