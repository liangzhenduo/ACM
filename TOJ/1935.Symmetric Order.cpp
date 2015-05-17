#include <iostream>
using namespace std;
int main()
{
    int n,k=0;
    while(cin >>n&&n)
    {
        k++;
        const int m=n;
        char name[m][26];
        for(int i=0;i<n/2;i++)
        {
            cin >>name[i];
            cin >>name[n-1-i];
        }
        if(n%2)
            cin >>name[n/2];
        cout <<"SET "<<k<<endl;
        for(int j=0;j<n;j++)
            cout <<name[j]<<endl;
    }
    return 0;
}
