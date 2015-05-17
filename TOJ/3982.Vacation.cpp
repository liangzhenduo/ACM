#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >>t;
    for(int k=0;k<t;k++)
    {
        int m,n;
        cin >>m>>n;
        const int o=n;
        int day[o];
        for(int j=0;j<n;j++)
            cin >>day[j];
        for(int i=n-1;i>=1;i--)
        {
            int maximum=day[0],maxI=0;
            for(int j=1;j<=i;j++)
                if(maximum<day[j])
                {
                    maximum=day[j];
                    maxI=j;
                }
            if(maxI!=i)
            {
                day[maxI]=day[i];
                day[i]=maximum;
            }
        }
        int z=0,l;
        for(l=0;l<n;l++)
        {
            z=z+day[l];
            if(z>m)
                break;
        }
        cout <<l<<endl;
    }
    return 0;
}
