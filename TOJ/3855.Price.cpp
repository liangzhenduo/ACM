#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
int main()
{
    int n,m;
    while(cin >>n>>m)
    {
        const int p=n,q=m;
        string dishes[p],dish[q];
        double price[p],sum=0;
        for(int i=0;i<n;i++)
            cin >>dishes[i]>>price[i];
        for(int i=0;i<m;i++)
        {
            cin >>dish[i];
            for(int j=0;j<n;j++)
                if(dish[i]==dishes[j])
                {
                    sum+=price[j];
                    break;
                }
        }
        cout <<fixed<<setprecision(2)<<sum<<endl;
    }
    return 0;
}

