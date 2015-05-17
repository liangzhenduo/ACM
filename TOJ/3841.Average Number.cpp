#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin >>n)
    {
        const int m=n;
        int num[m],sum=0;
        for(int i=0;i<n;i++)
        {
            cin >>num[i];
            sum=sum+num[i];
        }
        cout <<sum/n<<endl;
    }
    return 0;
}

