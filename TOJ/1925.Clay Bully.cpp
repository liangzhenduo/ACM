#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n,a,b,c;
    string name;
    while(cin >>n&&n!=-1)
    {
        int bully=0,victim=251;
        string bul,vic;
        while(n--)
        {
            cin >>a>>b>>c>>name;
            if(a*b*c>bully)
            {
                bully=a*b*c;
                bul=name;
            }
            if(a*b*c<victim)
            {
                victim=a*b*c;
                vic=name;
            }
        }
        cout <<bul<<" took clay from "<<vic<<"."<<endl;
    }
    return 0;
}
