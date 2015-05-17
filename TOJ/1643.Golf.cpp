#include <iostream>
using namespace std;
int main()
{
    int p,s,i=1;
    while(cin >>p>>s&&p+s)
    {
        cout <<"Hole #"<<i++<<endl;
        if(s==1)
            cout <<"Hole-in-one.";
        else if(s-p==-1)
            cout <<"Birdie.";
        else if(s-p==1)
            cout <<"Bogey.";
        else if(s-p==-2)
            cout <<"Eagle.";
        else if(s-p==-3)
            cout <<"Double Eagle.";
        else if(s-p>1)
            cout <<"Double Bogey.";
        else
            cout <<"Par.";
        cout <<endl<<endl;
    }
    return 0;
}
