#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int fib[5043]={1,1,2},t;
    for(int i=3;i<5044;i++)
        fib[i]=(fib[i-1]+fib[i-2])%10007;
    char text[10087];
    cin >>t;
    for(int i=1;i<=t;i++)
    {
        cin >>text;
        int n=1;
        for(int j=0,k=0;j<strlen(text)-3;k=0)
        {
            if(text[j]=='h'&&text[j+1]=='e')
            {
                while(text[j]=='h'&&text[j+1]=='e')
                {
                    k++;
                    j+=2;
                }
                n=(n*fib[k])%10007;
            }
            else
                j++;
        }
        cout <<"Case "<<i<<": "<<n<<endl;
    }
    return 0;
}
