#include <iostream>
using namespace std;
int main()
{
    int n,m,c;
    while(cin >>n>>m>>c&&n+m+c)
    {
        n-=7,m-=7;
        if((n*m)%2)
        {
            if(c)
                cout <<(n*m)/2+1<<endl;
            else
                cout <<(n*m)/2<<endl;
        }
        else
            cout <<(n*m)/2<<endl;
    }
    return 0;
}
