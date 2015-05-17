#include <iostream>
using namespace std;
int main()
{
    int n,d,m;
    while(cin >>n>>d&&n+d)
    {
        int alumni[100]={0},k=1;
        for(int i=0;i<d;i++)
            for(int j=0;j<n;j++)
            {
                cin >>m;
                alumni[j]+=m;
            }
        for(int i=0;i<d;i++)
            if(alumni[i]==d)
            {
                cout <<"yes"<<endl;
                k--;
                break;
            }
        if(k)
            cout <<"no"<<endl;
    }
    return 0;
}
