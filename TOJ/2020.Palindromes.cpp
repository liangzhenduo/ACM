#include <iostream>
#include <cstring>
using namespace std;
const char character[25] = "AEHIJLMOSTUVWXYZ123458";

    bool palindrome(char str[])
    {
        for(int i=0;i<strlen(str);i++)
            if(str[i]!=str[strlen(str)-1-i])
                return 0;
        return 1;
    }

    bool mirror(char str[])
    {
        for(int i=0;i<strlen(str);i++)
        {
            int j;
            for(j=0;j<25;j++)
                if(str[i]==character[j])
                    break;
            if(j==25)
                return 0;
        }
        return 1;
    }

int main()
{
    char str[21];
    while(cin >>str)
    {
        cout <<str<<" -- is ";
        if(palindrome(str)&&mirror(str))
            cout <<"a mirrored palindrome.";
        else if(palindrome(str)&&!mirror(str))
            cout <<"a regular palindrome.";
        else if(!palindrome(str)&&mirror(str))
            cout <<"a mirrored string.";
        else
            cout <<"not a palindrome.";
        cout <<endl<<endl;
    }
    return 0;
}
