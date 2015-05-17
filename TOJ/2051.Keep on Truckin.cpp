#include <iostream>
using namespace std;

    int min(int height1,int height2,int height3)
    {
        int result;
        if(height1<=height2&&height1<=height3)
            result = height1;
        else if (height2<height1&&height2<=height3)
            result = height2;
        else
            result = height3;
        return result;
    }

int main()
{
    int i,j,k;
    cin >>i>>j>>k;
    int m=min(i,j,k);
    if (m>168)
        cout <<"NO CRASH"<<endl;
    else
    {
        if(i<=168)
            cout <<"CRASH "<<i<<endl;
        else if(i>168&&j<=168)
            cout <<"CRASH "<<j<<endl;
        else
            cout <<"CRASH "<<k<<endl;
    }
    return 0;
}
