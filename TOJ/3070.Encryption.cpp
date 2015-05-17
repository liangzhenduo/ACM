#include <iostream>
using namespace std;
int main()
{
    int t,d;
    char text[101];
    cin >>t;
    while(t--)
    {
        cin >>text>>d;
        for(int i=0;text[i];i++)
            text[i]=(text[i]-97+d)%26+97;
        cout <<text<<endl;
    }
    return 0;
}
