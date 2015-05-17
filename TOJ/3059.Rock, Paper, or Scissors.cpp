#include <iostream>
using namespace std;
int main()
{
    int t,n;
    cin >>t;
    while(t--)
    {
        cin >>n;
        char p1,p2;
        int k=0;
        while(n--)
        {
            cin >>p1>>p2;
            if(p1=='R'&&p2=='S'||p1=='S'&&p2=='P'||p1=='P'&&p2=='R')
                k++;
            else if(p2=='R'&&p1=='S'||p2=='S'&&p1=='P'||p2=='P'&&p1=='R')
                k--;
        }
        if(k>0)
            cout <<"Player 1"<<endl;
        else if(k<0)
            cout <<"Player 2"<<endl;
        else
            cout <<"TIE"<<endl;
    }
    return 0;
}
