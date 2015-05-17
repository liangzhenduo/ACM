#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char oct[256],dec[256];
    while(cin >>oct)
    {
        memset(dec,0,sizeof(dec));
        int index=0,tmp,i,j;
        for(i=strlen(oct)-1;i>1;i--)
        {
            tmp=oct[i]-48;
            for(j=0;j<index||tmp;j++)
            {
                tmp*=10;
                if(j<index)
                    tmp+=(dec[j]-48);
                dec[j]=tmp/8+48;
                tmp%=8;
            }
            index=j;
        }
        cout <<oct<<" [8] = 0."<<dec<<" [10]"<<endl;
        memset(oct,0,sizeof(oct));
    }
    return 0;
}
