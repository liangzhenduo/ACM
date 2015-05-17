#include <iostream>
using namespace std;

    int sum(int base,int i)
    {
        int k=i,m,sum=0;
        while(k)
        {
            m=k%base;
            sum+=m;
            k/=base;
        }
        return sum;
    }

int main()
{
    for(int i=2992;i<10000;i++)
        if(sum(16,i)==sum(10,i)&&sum(12,i)==sum(10,i))
            cout<<i<<endl;
    return 0;
}
