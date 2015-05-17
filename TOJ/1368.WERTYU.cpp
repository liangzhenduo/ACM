#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char input[]="1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./";
    char output[]="`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.";
    char text[256];
    while(cin.getline(text,256))
    {
        int i,j;
        for(i=0;i<strlen(text);i++)
        {
            for(j=0;j<43;j++)
                if(text[i]==input[j])
                {
                    cout <<output[j];
                    break;
                }
            if(j==43)
                cout <<text[i];
        }
        cout <<endl;
    }
    return 0;
}
