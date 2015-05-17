#include <iostream>
using namespace std;
int main()
{
    for(int m=1;m>0;)
    {
        int i=0;
        int t;
        cin >>t;
        if(t==0)break;
        if(t>=1&&t<=1000)
        {
            m=t;
            for(int n=m;n>1;)
            {
                i++;
                if(n%2==0)
                    n=n/2;
                else
                    n=3*n+1;
            }
            cout <<i+1<<endl;
        }
    }
    return 0;
}
