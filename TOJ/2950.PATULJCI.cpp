#include <iostream>
using namespace std;
int main()
{
    int num[9],sum=0,p,q;
    for(int k=0;k<9;k++)
    {
        cin >>num[k];
        sum+=num[k];
    }
    for(int i=0;i<9;i++)
        for(int j=i+1;j<9;j++)
            if(sum-num[i]-num[j]==100)
            {
                p=i,q=j;
                break;
            }
    for(int k=0;k<9;k++)
        if(k!=p&&k!=q)
            cout <<num[k]<<endl;
    return 0;
}

