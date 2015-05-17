#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int p,q,r,s;
    while(cin >>p>>q>>r>>s)
    {
        double k=1;
        q=p-2*q>0?q:p-q;
        s=r-2*s>0?s:r-s;
        for(int i=1;i<=(q-s>0?q:s);i++)
        {
            if(i<=q)
                k=k/i*(p-q+i);
            if(i<=s)
                k=k*i/(r-s+i);
        }
        cout <<fixed<<setprecision(5)<<k<<endl;
    }
    return 0;
}
