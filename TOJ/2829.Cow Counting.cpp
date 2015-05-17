#include <iostream>
using namespace std;
int main()
{
    int n,l;
    while(cin >>n>>l)
    {
        int k=0,result;
        for(int i=1;k<n;i++)
        {
            int flag=0,m=i;
            while(m>0)
            {
                if(m%10==l)
                {
                    flag++;
                    break;
                }
                m/=10;
            }
            if(flag)
                continue;
            k++;
            result=i;
        }
        cout <<result<<endl;
    }
    return 0;
}
