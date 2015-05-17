#include <iostream>
using namespace std;
int main()
{
    int n,x,y;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        cin >>x>>y;
        if(x>=y&&(x+y)%2==0)
            cout <<(x+y)/2<<" "<<(x-y)/2<<endl;
        else
            cout <<"impossible"<<endl;
    }
    return 0;
}

