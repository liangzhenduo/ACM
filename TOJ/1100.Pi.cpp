#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    while(cin >>n&&n!=0)
    {
        const int m=n;
        int num[m];
        for(int l=0;l<n;l++)
            cin >>num[l];
        int t=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                int s,gcd;
                if(num[i]<num[j])
                    s=num[i];
                else
                    s=num[j];
                for(int k=s;;k--)
                    if(num[i]%k==0&&num[j]%k==0)
                    {
                         gcd=k;
                         break;
                    }
                if(gcd==1)
                    t++;
            }
        if(t==0)
            cout <<"No estimate for this data set."<<endl;
        else
            cout <<setiosflags(ios::fixed)<<setprecision(6)<<sqrt(3.0*n*(n-1)/t)<<endl;
    }
    return 0;
}

