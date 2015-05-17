#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    cout <<"PERFECTION OUTPUT"<<endl;
    while(cin >>n&&n)
    {
        int m=sqrt(n),sum=1;
        for(int i=2;i<=m;i++)
            if(n%i==0)
                sum+=i+n/i;
        if(m*m==n)
            sum-=m;
        cout <<setw(5)<<n<<"  ";;
        if(sum<n)
            cout <<"DEFICIENT"<<endl;
        else if(sum>n)
            cout <<"ABUNDANT"<<endl;
        else
            cout <<"PERFECT"<<endl;
    }
    cout <<"END OF OUTPUT"<<endl;
    return 0;
}
