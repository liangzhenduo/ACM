#include <iostream>
using namespace std;
int main()
{
    int t,n;
    cin >>t;
    for(int i=0;i<t;i++)
    {
        cin >>n;
        int j;
        for(j=0;j<n;j++)
        {
            int r=j,s=j;
            while(r>0)
            {
                s+=r%10;
                r/=10;
            }
            if(s==n)
                break;
        }
        if(j==n)
            j=0;
        cout <<j<<endl;
    }
    return 0;
}
