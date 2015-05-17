#include <iostream>
using namespace std;
int main()
{
    int n[6];
    while(1)
    {
        int high=0,low=10,sum=0;
        for(int i=0;i<6;i++)
        {
            cin >>n[i];
            high=n[i]>high?n[i]:high;
            low=n[i]<low?n[i]:low;
            sum+=n[i];
        }
        if(!sum)
            break;
        cout <<(double)(sum-high-low)/4<<endl;
    }
    return 0;
}
