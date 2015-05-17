#include <iostream>
using namespace std;

    void sorting(int list[],int n)
    {
        for(int i=n-1;i>=1;i--)
        {
            int maximum=list[0],maxI=0;
            for(int j=1;j<=i;j++)
                if(maximum<list[j])
                {
                    maximum=list[j];
                    maxI=j;
                }
            if(maximum!=i)
            {
                list[maxI]=list[i];
                list[i]=maximum;
            }
        }
    }

int main()
{
    int n;
    while(cin >>n)
    {
        const int m=n;
        int cow[m],row[m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin >>cow[j];
            sorting(cow,n);
            row[i]=cow[n/2];
        }
        sorting(row,n);
        cout <<row[n/2]<<endl;
    }
    return 0;
}
