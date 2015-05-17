#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin >>n)
    {
        int m=1,i=1;
        while(m%n!=0)
        {
            m=(10*m+1)%n;
            i++;
        }
        cout <<i<<endl;
    }
    return 0;
}
