#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin >>n;
    for(int i=1;i<=n;i++)
    {
        cin >>m;
        if(m==2||m==4)
            cout <<"Case "<<i<<": 2"<<endl;
        else
            cout <<"Case "<<i<<": "<<(m-1)/6+1<<endl;
    }
    return 0;
}

