#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin >>n&&n)
    {
        const int m=n;
        int v[m],t[m],k=32400,o;
        for(int i=0;i<n;i++)
        {
            cin >>v[i]>>t[i];
            if(16200%v[i])
                o=16200/v[i]+1;
            else
                o=16200/v[i];
            if(t[i]>=0&&o+t[i]<k)
                k=o+t[i];
        }
        cout <<k<<endl;
    }
    return 0;
}
