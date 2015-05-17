#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char departure[100];
    string arrival;
    char code;
    while(0<1)
    {
        int actual,summary=0,k=0;
        while(0<1)
        {
            cin >>departure;
            if(departure[0]=='#')
            {
                k=1;
                break;
            }
            if(departure[0]=='0')
            {
                cout <<summary<<endl;
                break;
            }
            cin >>arrival>>actual>>code;
            if(code=='F')
                actual=2*actual;
            else if(code=='B')
                actual=1.5*actual;
            else if(code=='Y')
                if(actual<=500)
                    actual=500;
            summary=summary+actual;
        }
        if(k==1)
            break;
    }
    return 0;
}

