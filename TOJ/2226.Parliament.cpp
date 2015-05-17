#include <iostream>
using namespace std;
int res[1001];
int main()
{
    int n;
    while(cin >>n)
    {
        int k=0;
        res[++k]=2;
        n-=2;
        while(res[k]<n)
        {
            int t=res[k];
            res[++k]=t+1;
            n-=res[k];
        }
        for(int i=k;i>0;i--)
        {
            res[i]+=(n+i-1)/i;
            n-=(n+i-1)/i;
        }
        for(int i=1;i<k;i++)
            cout <<res[i]<<" ";
        cout <<res[k]<<endl;
    }
    return 0;
}
