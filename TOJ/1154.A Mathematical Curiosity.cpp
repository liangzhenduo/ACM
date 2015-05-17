#include <iostream>
using namespace std;
int main()
{
    int n,m,o=0;
    while(cin >>n>>m&&n!=0)
    {
        o++;
        int k=0;
        for(int i=1;i<n;i++)
            for(int j=i+1;j<n;j++)
                if((i*i+j*j+m)%(i*j)==0)
                    k++;
        cout <<"Case "<<o<<": "<<k<<endl;
    }
    return 0;
}
