#include <iostream>
using namespace std;
int num[32768];
int main()
{
    int n,i,j;
    for(i=2;i<183;i++)
        if(num[i]==0)
            for(j=i*i;j<32768;j+=i)
                num[j]=1;
    while(cin >>n&&n)
    {
        int k=0;
        for(i=2;i<=n/2;i++)
            if(num[i]==0&&num[n-i]==0)
                k++;
        cout <<k<<endl;
    }
    return 0;
}
