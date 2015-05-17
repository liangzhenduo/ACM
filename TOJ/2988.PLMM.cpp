#include <iostream>
using namespace std;
int main()
{
    int m;
    cin >>m;
    for(int i=0;i<m;i++)
    {
        double k=0,n,l,w,p,s;
        cin >>n>>l>>w;
        for(int j=0;j<n;j++)
        {
            cin >>p>>s;
            if(p*w<=l*(w-s))
                k++;
        }
        cout <<k<<endl;
    }
    return 0;
}

