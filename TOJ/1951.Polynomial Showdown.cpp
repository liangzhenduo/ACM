#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int num[9],i,j,k;
    while(cin >>num[8])
    {
        k=num[8];
        for(i=7;i>=0;i--)
        {
            cin >>num[i];
            if(num[i]&&!k)
                k=i;
        }
        for(i=8;i>0;i--)
            if(num[i])
            {
                if(num[i]==-1)
                    cout <<"-";
                else if(num[i]!=1)
                    cout <<num[i];
                cout <<"x";
                if(i>1)
                    cout <<"^"<<i;
                break;
            }
        for(j=i-1;j>0;j--)
        {
            if(!num[j])
                continue;
            cout <<(num[j]>0?" + ":" - ");
            if(abs(num[j])!=1)
                cout <<abs(num[j]);
            cout <<"x";
            if(j>1)
                cout <<"^"<<j;
        }
        if(!k)
            cout <<num[0];
        else if(num[0])
            cout <<(num[0]>0?" + ":" - ")<<abs(num[0]);
        cout <<endl;
    }
    return 0;
}
