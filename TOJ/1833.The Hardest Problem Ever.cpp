#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string state;
    while(cin >>state&&state!="ENDOFINPUT")
    {
        char text[256];
        cin.get();
        cin.getline(text,256);
        cin >>state;
        for(int i=0;i<strlen(text);i++)
        {
            if(text[i]<70&&text[i]>64)
                text[i]+=21;
            else if(text[i]<91&&text[i]>69)
                text[i]-=5;
            cout <<text[i];
        }
        cout <<endl;
    }
    return 0;
}

