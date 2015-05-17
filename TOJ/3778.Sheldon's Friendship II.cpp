#include <iostream>
using namespace std;
int main()
{
    char p;
    int value,m=0;
    while(cin >>p)
        if(p=='n')
        {
            cin >>value;
            if(value>m)
                m=value;
        }
    cout <<m*m<<endl;
    return 0;
}
