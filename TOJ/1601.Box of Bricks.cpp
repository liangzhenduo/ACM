#include <iostream>
using namespace std;
int main()
{
    int n,j=0;
    while(cin >>n&&n)
    {
        j++;
        const int m=n;
        int height[m],k=0;
        for(int i=0;i<n;i++)
        {
            cin >>height[i];
            k+=height[i];
        }
        int average=k/n,o=0;
        for(int i=0;i<n;i++)
            if(height[i]<average)
                o+=average-height[i];
        cout <<"Set #"<<j<<endl<<"The minimum number of moves is "<<o<<"."<<endl<<endl;;
    }
    return 0;
}

