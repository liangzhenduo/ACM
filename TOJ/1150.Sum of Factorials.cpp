#include <iostream>
using namespace std;
int main()
{
    int factorial[11],m;
    factorial[0]=1;
    for(int i=1;i<11;i++)
        factorial[i]=i*factorial[i-1];
    while(cin >>m&&m>=0)
    {
        if(m)
        {
            for(int i=9;i>=0;i--)
                if(m>=factorial[i])
                    m-=factorial[i];
            if(m)
                cout <<"NO"<<endl;
            else
                cout <<"YES"<<endl;
        }
        else
            cout <<"NO"<<endl;
    }
    return 0;
}
