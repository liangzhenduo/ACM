#include <iostream>
using namespace std;
int main()
{
    int num1[1000],num2[1000],t,m,n,p,q,k;
    cin >>t;
    while(t--)
    {
        for(int i=0;i<1000;i++)
            num1[i]=0,num2[i]=0;
        cin >>m>>n;
        while(m--)
        {
            cin >>p;
            num1[p]++;
        }
        while(n--)
        {
            cin >>q;
            num2[q]++;
        }
        k=0;
        for(int i=0;i<1000;i++)
        {
            if(!k&&num1[i]*num2[i]>0)
            {
                cout <<i;
                k=1;
            }
            else if(k&&num1[i]*num2[i]>0)
                cout <<" "<<i;
        }
        cout <<endl;
    }
    return 0;
}

