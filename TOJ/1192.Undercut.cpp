#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >>n;
    while(n!=0)
    {
        const int m=n;
        int A[m],B[m],a=0,b=0;
        for(int i=0;i<n;i++)
            cin >>A[i];
        for(int i=0;i<n;i++)
            cin >>B[i];
        for(int i=0;i<n;i++)
        {
            if(A[i]==2&&B[i]==1)
                b+=6;
            else if(A[i]==1&&B[i]==2)
                a+=6;
            else if(A[i]-B[i]==1)
                b+=A[i]+B[i];
            else if(B[i]-A[i]==1)
                a+=A[i]+B[i];
            else if(A[i]-B[i]>1)
                a+=A[i];
            else if(B[i]-A[i]>1)
                b+=B[i];
        }
        cout <<"A has "<<a<<" points. B has "<<b<<" points."<<endl;
        cin >>n;
        if(n!=0)
            cout<<endl;
    }
    return 0;
}
