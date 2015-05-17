#include <iostream>
using namespace std;
int main()
{
    int t,m,n;
    cin >>t;
    for(int l=1;l<=t;l++)
    {
        cin >>m>>n;
        const int o=n;
        int stamp[o],k=0,j;
        for(j=0;j<n;j++)
            cin >>stamp[j];
        for(int i=n-1;i>0;i--)
        {
            int maximum=stamp[0],maxI=0;
            for(int j=1;j<=i;j++)
                if(maximum<stamp[j])
                {
                    maximum=stamp[j];
                    maxI=j;
                }
            if(maxI!=i)
            {
                stamp[maxI]=stamp[i];
                stamp[i]=maximum;
            }
        }
        for(j=n-1;j>=0;j--)
        {
            if(k<m)
                k+=stamp[j];
            else
                break;
        }
        cout <<"Scenario #"<<l<<":"<<endl;
        if(k<m)
            cout <<"impossible"<<endl<<endl;
        else
            cout <<n-j-1<<endl<<endl;
    }
    return 0;
}

