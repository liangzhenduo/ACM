#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char plaintext[128],substitution[128],text[65];
    cin.getline(plaintext,128);
    cin.getline(substitution,128);
    int i,j,l=strlen(plaintext);
    for(i=0;i<l;i++)
        cout <<substitution[i];
    cout <<endl;
    for(i=0;i<l;i++)
        cout <<plaintext[i];
    cout <<endl;
    while(cin.getline(text,65))
    {
        for(i=0;i<strlen(text);i++)
        {
            for(j=0;j<l;j++)
                if(text[i]==plaintext[j])
                {
                    cout <<substitution[j];
                    break;
                }
            if(j==l)
                cout <<text[i];
        }
        cout <<endl;
    }
    return 0;
}
