#include <iostream>
using namespace std;
int main()
{
    int ca,n,sequence;
    cin >>ca;
    while(ca--)
    {
        int num[10001]={0},k=0;
        cin >>n;
        while(n--)
        {
            cin >>sequence;
            num[sequence]++;
        }
        for(int i=0;i<10001;i++)
            if(num[i]>k)
                k=num[i];
        cout <<k<<endl;
    }
    return 0;
}
