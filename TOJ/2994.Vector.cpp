#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >>t;
    for(int k=0;k<t;k++)
    {
        int n;
        cin >>n;
        const int m=n;
        int p[m],q[m];
        for(int i=0;i<m;i++)
            cin >>p[i];
        for(int i=0;i<m;i++)
            cin >>q[i];
        int s=0;
        for(int j=0;j<m;j++)
            s=s+p[j]*q[j];
        cout <<s<<endl;
    }
    return 0;
}

