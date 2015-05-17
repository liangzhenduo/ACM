#include <iostream>
using namespace std;
int main()
{
    int tri[33],k;
    tri[0]=1,tri[2]=3;
    for(int i=4;i<31;i+=2)
    {
        tri[i]=tri[2]*tri[i-2];
        k=i-4;
        while(k>=0)
        {
            tri[i]+=2*tri[k];
            k-=2;
        }
    }
    int n;
    while(cin >>n&&n>=0)
    {
        if(n%2)
            cout <<0<<endl;
        else
            cout <<tri[n]<<endl;
    }
    return 0;
}
