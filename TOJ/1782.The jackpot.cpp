#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin >>n&&n)
    {
        int bet,win=0,maximum=0;
        while(n--)
        {
            cin >>bet;
            win+=bet;
            if(win<0)
                win=0;
            if(win>maximum)
                maximum=win;
        }
        if(maximum)
            cout <<"The maximum winning streak is "<<maximum<<"."<<endl;
        else
            cout <<"Losing streak."<<endl;
    }
    return 0;
}
