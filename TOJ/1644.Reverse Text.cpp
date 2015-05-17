#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    cin >>n;
    char go[1];
    cin.getline(go,1);
    char text[71];
    for (int i=0;i<n;i++)
    {
        cin.getline(text,71);
        int length=strlen(text)-1;
        for (int i=0;i<=length/2;i++)
        {
            char m=text[length-i];
            text[length-i]=text[i];
            text[i]=m;
        }
        for(int x=0;x<=length;x++)
            cout <<text[x];
        cout <<'\n';
    }
    return 0;
}

