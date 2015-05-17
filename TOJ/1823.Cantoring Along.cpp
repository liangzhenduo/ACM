#include <iostream>
using namespace std;

    void approximation(int m)
    {
        if(m==1)
            cout <<"-";
        else
            approximation(m/3);

        for(int i=0;i<m/3;i++)
            cout <<" ";
        if(m>=3)
            approximation(m/3);
    }

int main()
{
    int n;
    while(cin >>n)
    {
        int m=1;
        for(int i=0;i<n;i++)
            m=3*m;
        approximation(m);
        cout <<endl;
    }
    return 0;
}

