#include <iostream>
using namespace std;
int main()
{
    int t,n,num[1001],k;
    cin >>t;
    while(t--)
    {
        cin >>n;
        for(int i=0;i<n;i++)
            cin >>num[i];
        for(int i=n-1;i>0;i--)
        {
            int maximum=num[0],maxI=0;
            for(int j=1;j<=i;j++)
                if(maximum<num[j])
                {
                    maximum=num[j];
                    maxI=j;
                }
            if(maxI!=i)
            {
                num[maxI]=num[i];
                num[i]=maximum;
            }
        }
        k=num[0]*n;
        for(int j=0;j<n;j++)
            if(num[j]*(n-j)>k)
                k=num[j]*(n-j);
        cout <<k<<endl;
    }
    return 0;
}
