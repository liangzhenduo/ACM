#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >>n;
    for(int i=1;i<=n;i++)
    {
        int m,k=0;
        cin >>m;
        const int o=m;
        char sheep[o][10];
        for(int j=0;j<m;j++)
        {
            cin >>sheep[j];
            if(sheep[j][0]=='s'&&sheep[j][1]=='h'&&sheep[j][2]=='e'&&sheep[j][3]=='e'&&sheep[j][4]=='p'&&sheep[j][5]=='\0')
                k++;
        }
        cout <<"Case "<<i<<": This list contains "<<k<<" sheep."<<endl;
        if(i<n)
            cout <<endl;
    }
    return 0;
}
