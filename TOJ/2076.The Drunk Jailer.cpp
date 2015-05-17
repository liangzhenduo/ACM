#include<iostream>
using namespace std;

    int func(int m)
    {
        const int n=m;
        int cell[n];
        for(int i=0;i<=n;i++)
            cell[i]=0;
        for(int k=1;k<=n;k++)
        {
            for(int i=0;i<=n;i++)
            {
                if(i%k==0)
                {
                    if(cell[i]==0)
                        cell[i]=1;
                    else
                        cell[i]=0;
                }
            }
        }
        int c=0;
        for(int i=1;i<=n;i++)
        {
            if(cell[i]==1)
                c++;
        }
        return c;
    }

int main()
{
    int cas;
    cin >>cas;
    const int CAS=cas;
    int list[CAS];
    for(int i=0;i<cas;i++)
        cin >>list[i];
    for(int i=0;i<cas;i++)
        cout <<func(list[i])<<endl;
    return 0;
}
