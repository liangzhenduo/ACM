#include <iostream>
using namespace std;
int main()
{
    int c,n;
    cin >>c>>n;
    const int m=n,d=c;
    int value[m];
    for(int i=1;i<=n;i++)
        cin >>value[i];
    int change[d];
    change[0]=0;
    for(int i=1;i<=c;i++)
    {
        int minimum=c;
        for(int j=1;j<=n;j++)
            if(i>=value[j]&&change[i-value[j]]<minimum)
                minimum=change[i-value[j]];
        change[i]=minimum+1;
    }
    cout <<change[c]<<endl;
    return 0;
}




