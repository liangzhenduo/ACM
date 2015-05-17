#include <iostream>
using namespace std;
int main()
{
    int t,n;
    cin >>t;
    while(t--)
    {
        int carry=0,l=0,k=0;
        cin >>n;
        if (n>10)
        {
            while(n>10)
            {
                k=n%10;
                carry=k+carry<5?0:1;
                l++;
                n/=10;
            }
            cout <<n+carry;
            for(int j=0;j<l;j++)
                cout <<0;
            cout <<endl;
        }
        else
            cout <<n<<endl;
    }
    return 0;
}
