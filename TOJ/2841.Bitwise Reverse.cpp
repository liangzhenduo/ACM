#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    while(cin >>n&&n!=0)
    {
        int binary[20],k=0,i,j;
        for(i=0;n>0;i++)
        {
            binary[i]=n%2;
            n/=2;
        }
        for(j=0;j<i;j++)
            k+=pow(2,i-j-1)*binary[j];
        cout <<k<<endl;
    }
    return 0;
}

