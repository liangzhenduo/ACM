#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char n[1001];
    int k,a[1001];
    while(cin >>n)
    {
        k=0;
        for(int i=0;i<strlen(n);i++)
        {
            a[i]=(10*k+n[i]-48)/3;
            k=(10*k+n[i]-48)%3;
        }
        if(a[0])
            cout <<a[0];
        for(int i=1;i<strlen(n);i++)
            cout <<a[i];
        cout <<endl;
    }
    return 0;
}
