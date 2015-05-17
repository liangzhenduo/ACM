#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int a,b,k;
    while(cin>>a>>b)
    {
        cout<<setw(10)<<a<<setw(10)<<b<<"    ";
        k=a%b;
        while(k)
        {
            a=b;
            b=k;
            k=a%b;
        }
        if(b-1)
            cout<<"Bad";
        else
            cout<<"Good";
        cout <<" Choice"<<endl<<endl;
    }
    return 0;
}
