#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
    int t;
    char binary[64];
    cin >>t;
    while(t--)
    {
        int k=0,m=1;
        cin >>binary;
        for(int i=strlen(binary)-1,j=0;i>=0;i--,j++)
        {
            k+=m*(binary[i]-48)*pow(2,j);
            if(j==2)
            {
                j=-1;
                m*=10;
            }
        }
        cout <<k<<endl;
    }
    return 0;
}

