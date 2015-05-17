#include <iostream>
using namespace std;
int main()
{
    int n,k,f,g=0,h=0;
    cin >>n>>k;
    const int m=n,l=k;
    int a[m],b[n],vote[l];
    for(int i=0;i<n;i++)
        cin >>a[i]>>b[i];
    for(int i=0;i<k;i++)
    {
        f=0;
        for(int j=0;j<n;j++)
            if(a[j]>f)
            {
                f=a[j];
                h=j;
            }
        a[h]=0;
        vote[i]=h;
    }
    for(int i=0;i<k;i++)
        if(b[vote[i]]>g)
        {
            g=b[vote[i]];
            h=vote[i];
        }
    cout <<h+1<<endl;
    return 0;
}

