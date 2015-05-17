#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    cin >>n;
    char input[51],output[51];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<51;j++)
        {
            input[j]=0;
            output[j]=0;
        }
        cin >>input;
        for(int j=0;j<strlen(input);j++)
        {
            int k=input[j];
            if(input[j]=='Z')
                output[j]='A';
            else
                output[j]=k+1;
        }
        cout <<"String #"<<i<<endl;
        cout <<output<<endl<<endl;
    }
    return 0;
}

