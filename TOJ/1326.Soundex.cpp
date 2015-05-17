#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char letter[20];
    int value[26]={0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};
    while(cin >>letter)
    {
        for(int i=0;i<strlen(letter);i++)
            if(value[letter[i]-65]&&value[letter[i]-65]!=value[letter[i-1]-65])
            cout <<value[letter[i]-65];
        cout <<endl;
    }
    return 0;
}
