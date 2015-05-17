#include <iostream>
#include <cmath>
using namespace std;
int num[10001]={1,1};
int main()
{
    for(int i=2;i<10001;i++)
        for(int j=2;j<=sqrt(i);j++)
            if(i%j==0)
            {
                num[i]=1;
                break;
            }
    int a,b,k;
    while(cin >>a>>b)
    {
        k=0;
        for(int i=a;i<=b;i++)
            if(!num[i])
                k++;
        cout <<(num[k]?"NO":"YES")<<endl;
    }
    return 0;
}
