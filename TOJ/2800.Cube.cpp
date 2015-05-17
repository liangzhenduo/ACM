#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        cin >>m;
        cout <<m*m-m+1<<" "<<m*m+m-1<<endl;
    }
    return 0;
}

