#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin >>n&&n)
    {
        const int m=n;
        int num[m],k=0;
        for(int i=0;i<n;i++)
            cin >>num[i];
        for(int i=n;i>0;i--)
        {
            int maximum=num[0];
            int maxI=0;
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
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i-1;j>=0;j--)
            {
                for(int l=j-1;l>=0;l--)
                    if(num[i]-num[j]==num[l])
                    {
                        k=num[i];
                        break;
                    }
                if(k)
                    break;
            }
            if(k)
                break;
        }
        if(k)
            cout <<k<<endl;
        else
            cout <<-1<<endl;
    }
    return 0;
}
