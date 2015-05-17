#include <iostream>
using namespace std;
int main()
{
    int n,r,y,k;
    while(cin >>n&&n)
    {
        const int m=n;
        char ball[m];
        cin >>ball;
        r=0,y=0,k=0;
        for(int i=0;i<n;i++)
        {
            if(ball[i]=='R')
                r++;
            else if(ball[i]=='Y')
                y++;
            else if(ball[i]=='B'&&r==7||ball[i]=='L'&&y<7)
                k++;
        }
        if(k)
            cout <<"Red"<<endl;
        else
            cout <<"Yellow"<<endl;
    }
    return 0;
}

