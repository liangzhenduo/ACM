#include <iostream>
using namespace std;
int main()
{
    int p,q;
    while(cin >>p>>q)
        for(int i=1;i<=p;i++)
            if(p%i==0)
                for(int j=1;j<=q;j++)
                    if(q%j==0)
                        cout <<i<<" "<<j<<endl;
    return 0;
}

