#include <iostream>
using namespace std;

    int pow(int m,int n)
    {
        if(n==1)
            return m;
        int k=pow(m,n/2);
        k=(k%2006)*(k%2006)%2006;
        if(n%2)
            k=(k%2006)*(m%2006)%2006;
        return k;
    }

int main()
{
    int n;
    while(cin >>n&&n)
        cout <<pow(n,n)<<endl;
    return 0;
}
