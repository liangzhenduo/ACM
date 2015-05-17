#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int b;
    while(cin >>b&&b)
    {
        int k=0,sum=0;
        char n[256];
        cin >>n;
        for(int i=0;i<strlen(n);i++)
        {
            sum+=n[i]-48;
            k=k*b+n[i]-48;
        }
        if(k%sum)
            cout <<"no"<<endl;
        else
            cout <<"yes"<<endl;
    }
    return 0;
}
