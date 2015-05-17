#include <iostream>
using namespace std;
int main()
{
    int e,f,c;
    while(cin >>e>>f>>c)
    {
        int bottle=e+f,k=0;
        while(bottle>=c)
        {
            k=k+bottle/c;
            bottle=bottle%c+bottle/c;
        }
        cout <<k<<endl;
    }
    return 0;
}

