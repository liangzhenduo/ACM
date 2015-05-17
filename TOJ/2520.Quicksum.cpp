#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char text[256];
    while(cin.getline(text,256)&&text[0]!='#')
    {
        int k=0;
        for(int i=0;i<strlen(text);i++)
            if(text[i]!=' ')
                k=k+(i+1)*(text[i]-64);
        cout <<k<<endl;
    }
    return 0;
}
