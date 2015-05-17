#include <iostream>
using namespace std;
int main()
{
    double hang[278],n;
    hang[1]=0;
    for(int i=2;i<278;i++)
        hang[i]=hang[i-1]+(double)1/i;
    while(cin >>n&&n)
    {
        int j;
        for(j=1;j<278;j++)
            if(hang[j]<=n&&hang[j+1]>n)
                break;
        cout <<j<<" card(s)"<<endl;
    }
    return 0;
}

