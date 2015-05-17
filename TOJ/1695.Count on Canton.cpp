#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin >>n&&n!=0)
    {
        int i,s=0,t,x,y;
        for(i=1;;i++)
        {
            s=s+i;
            if(s>=n)
                break;
        }
        s=s-i;
        t=n-s;
        if(i%2==1)
        {
            y=i-t+1;
            x=i+1-y;
        }
        else
        {
            x=i+1-t;
            y=i+1-x;
        }
        cout <<"TERM "<<n<<" IS "<<y<<"/"<<x<<endl;
    }
    return 0;
}

