#include <iostream>
using namespace std;
int main()
{
    int a,b,c,d,n,i=1;
    cin >>n;
    while(n--)
    {
        cin >>a>>b>>c>>d;
        cout <<"Scenario #"<<i++<<":"<<endl;
        if((a+b+c+d)%2)
            cout <<1;
        else
            cout <<0;
        cout <<endl<<endl;
    }
    return 0;
}
