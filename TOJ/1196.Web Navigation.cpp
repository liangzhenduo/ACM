#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string key,url;
    string history[101];
    history[0]="http://www.acm.org/";
    int i=0,j=0;
    while(cin >>key&&key!="QUIT")
    {
        if(key=="VISIT")
        {
            cin >>url;
            history[++i]=url;
            j=i;
            cout <<history[j]<<endl;
        }
        else if(key=="BACK"&&i)
            cout <<history[--i]<<endl;
        else if(key=="FORWARD"&&i<j)
            cout <<history[++i]<<endl;
        else
            cout <<"Ignored"<<endl;
    }
    return 0;
}
