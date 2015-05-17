#include <iostream>
using namespace std;
int main()
{
    int m,n;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        cin >>m;
        int sum=0;
        while(m>0)
        {
            sum+=m%10;
            m=m/10;
        }
        cout <<sum<<endl;
    }
    return 0;
}

