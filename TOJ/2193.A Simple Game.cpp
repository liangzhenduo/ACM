#include <iostream>
using namespace std;
int main()
{
    int n,m;
    while(cin >>n>>m&&n)
    {
        if(n%(m+1))
            cout <<"Just Do It."<<endl;
        else
            cout <<"Think About It."<<endl;
    }
    return 0;
}
