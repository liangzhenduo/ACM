#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin >>n;
    while(n--)
    {
        cin >>m;
        const int o=m;
        int num[o];
        for(int j=0;j<m;j++)
            cin >>num[j];
        for(int i=1;i<m;i++)
            for(int j=0;j<m-i;j++)
                num[j]=num[j+1]-num[j];
        cout <<num[0]<<endl;
    }
    return 0;
}

