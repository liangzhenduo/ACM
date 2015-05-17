#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char num[1024];
    while(cin >>num&&num[0]!=48)
    {
        int n=0,k;
        for(int i=0;i<strlen(num);i++)
            n+=num[i]-48;
        while(n>9)
        {
            k=0;
            while(n>0)
            {
                k+=n%10;
                n/=10;
            }
            n=k;
        }
        cout <<n<<endl;
    }
    return 0;
}

