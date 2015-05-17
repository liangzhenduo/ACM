#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        char m[101],n[101];
        cin >>m>>n;
        if((m[strlen(m)-1]+n[strlen(n)-1])%2)
            cout <<"CANNOT"<<endl;
        else
            cout <<"MEET"<<endl;
    }
    return 0;
}
