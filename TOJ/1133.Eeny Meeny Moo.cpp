#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin >>n&&n)
    {
        int m=0,k=1;
        while(++m&&k)
        {
            k=0;
            for(int i=2;i<n;i++)
                k=(k+m)%i;
            if(!k)
                cout <<m<<endl;
        }
    }
    return 0;
}
