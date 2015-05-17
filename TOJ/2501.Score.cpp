#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        char result[80];
        int k[80],m=0;
        for(int j=0;j<80;j++)
        {
            result[j]='X';
            k[j]=0;
        }
        cin >>result;
        for(int j=0;j<80;j++)
        {
            if(result[j]=='O'&&result[j-1]!='O')
                k[j]=1;
            else if(result[j]=='O'&&result[j-1]=='O')
                k[j]=k[j-1]+1;
            m=m+k[j];
        }
        cout <<m<<endl;
    }
    return 0;
}

