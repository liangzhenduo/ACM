#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin >>n)
    {
        const int m=n;
        int num[m];
        for(int i=0;i<n;i++)
            cin >>num[i];
        for(int i=n-1;i>=1;i--)
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
        for(int i=0;i<n;i++)
        {
             if(i==n-1)
                cout <<num[i]<<endl;
             else
                cout <<num[i]<<" ";
        }
    }
    return 0;
}

