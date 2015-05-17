#include <iostream>
#include <cmath>
using namespace std;
int num[224738],prime[20001];
int main()
{
    int index=0,I;
    for(int i=2;i<224738;i++)
        for(int j=2;j<=sqrt(i);j++)
            if(i%j==0)
            {
                num[i]=1;
                break;
            }
    for(int i=2;i<224738;i++)
        if(!num[i])
            prime[++index]=i;
    while(cin >>I)
        cout <<prime[2*I-1]<<prime[2*I]<<endl;
    return 0;
}
