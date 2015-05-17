#include <iostream>
using namespace std;
int main()
{
    int joseph[14],k,i,j;
    for (int l=1;l<14&&l;l++)
    {
        int n=2*l,m=l+1;
        while(m)
        {
            for(i=0,j=0;i<l;i++)
            {
                j=(m-1+j)%(n-i);
                if(j<l)
                    break;
            }
            if(i==l)
            {
                joseph[l]=m;
                break;
            }
            if(m%(l+1))
                m+=l;
            else
                m++;
        }
    }
    while(cin >>k&&k)
        cout <<joseph[k]<<endl;
    return 0;
}
