#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin >>n&&n>=0)
    {
        int k=0;
        for(int i=10;i>1;i--)
        {
            int m=n,j=i+1;
            while(j--)
            {
                if((m-1)%i)
                    break;
                else
                    m-=(m-1)/i+1;
            }
            if(j==0&&m%i==0)
            {
                k=i;
                break;
            }
        }
        if(k)
            cout <<n<<" coconuts, "<<k<<" people and 1 monkey"<<endl;
        else
            cout <<n<<" coconuts, no solution"<<endl;
    }
    return 0;
}
