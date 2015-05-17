#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    while(cin >>n)
    {
        int m=1;
        string prairie("@");
        for(int i=0;i<n;i++)
        {
            prairie.append(m,' ');
            prairie.append(prairie,0,m);
            m*=3;
        }
        cout <<prairie<<endl;
    }
    return 0;
}
