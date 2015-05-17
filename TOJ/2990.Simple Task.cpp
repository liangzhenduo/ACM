#include <iostream>
using namespace std;
int main()
{
    int o;
    cin >>o;
    for(int l=0;l<o;l++)
    {
        int m,n;
        cin >>m;
        const int p=m;
        int A[p];
        for(int i=0;i<m;i++)
            cin >>A[i];
        cin >>n;
        const int q=n;
        int B[q];
        for(int i=0;i<n;i++)
            cin >>B[i];
        int k=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(A[i]+B[j]==0)
                    k++;
        cout <<k<<endl;
    }
    return 0;
}

