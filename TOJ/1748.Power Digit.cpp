#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int digit[10][4]=
    {
        0,0,0,0,
        1,1,1,1,
        6,2,4,8,
        1,3,9,7,
        6,4,6,4,
        5,5,5,5,
        6,6,6,6,
        1,7,9,3,
        6,8,4,2,
        1,9,1,9
    };
    string m,n;
    while(cin >>m>>n&&(m!="0"||n!="0"))
    {
        if(n=="0")
            cout <<1<<endl;
        else
        {
            int k=m.at(m.length()-1)-48,o=0;
            for(int i=0;i<n.length();i++)
                o=(10*o+n[i]-48)%4;
            cout <<digit[k][o]<<endl;
        }
    }
    return 0;
}

