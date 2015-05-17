#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char input[101],output[200];
    while(cin >>input)
    {
        int k=1,j=0,l=strlen(input),p=0,q=0;
        for(int i=0;i<strlen(input);i++)
        {
            if(input[i]==95)
                p++;
            if(input[i]<95)
                q++;
            if(p*q||!(input[0]>96&&input[0]<123)||!(input[i]>64&&input[i]<91||input[i]>96&&input[i]<123||input[i]==95)||input[strlen(input)-1]==95||input[i]==95&&input[i+1]<97)
            {
                k=0;
                break;
            }
            else if(input[i]==95&&input[i+1]>96)
            {
                output[i-j]=input[i+1]-32;
                j++;
                l--;
                i++;
            }
            else if(input[i]<91)
            {
                output[i-j]=95;
                j--;
                output[i-j]=input[i]+32;
                l++;
            }
            else
                output[i-j]=input[i];
        }
        if(k)
        {
            for(int i=0;i<l;i++)
                cout <<output[i];
            cout <<endl;
        }
        else
            cout <<"Error!"<<endl;
    }
    return 0;
}

