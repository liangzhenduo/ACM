#include <iostream>
using namespace std;
int main()
{
    int n=0,u=0,d=0;
    while(cin >>n>>u>>d)
    {
        if(n==0)
            break;
        if(n>u&&u<=d)
            continue;
        int h=0,i;
        for(i=1;;i=i+1)
        {
            if(i%2==0)
                h=h-d;
            else
                h=h+u;
            if(n<=h)
                break;
        }
            cout <<i<<endl;
    }
    return 0;
}

