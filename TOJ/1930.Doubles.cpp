#include <iostream>
using namespace std;
int main()
{
    int num[16];
    while(cin >>num[0]&&num[0]!=-1)
    {
        int n,k=0;
        for(int i=1;i<16;i++)
        {
            cin >>num[i];
            if(num[i]==0)
            {
                n=i;
                break;
            }
        }
        for(int i=0;i<n;i++)
            if(num[i]%2==0)
                for(int j=0;j<n;j++)
                    if(2*num[j]==num[i])
                        k++;
        cout <<k<<endl;
    }
    return 0;
}

