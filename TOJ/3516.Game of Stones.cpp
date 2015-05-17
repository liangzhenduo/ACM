#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char n[51],m[51];
    while(cin >>n>>m)
    {
        if(n[strlen(n)-1]==m[strlen(m)-1])
            cout <<"No"<<endl;
        else
            cout <<"Yes"<<endl;
    }
    return 0;
}

