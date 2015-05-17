#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >>n;
    const int m=n;
    int debt[m],k=n;
    for(int i=0;i<n;i++)
        cin >>debt[i];
    int money=0,position;
    for(int j=0;j<n;j++)
    {
        money+=debt[j];
        if(money<0&&money-debt[j]>=0)
            position=j;
        else if(money>=0&&money-debt[j]<0)
            k+=2*(j-position);
    }
    cout <<k<<endl;
    return 0;
}

