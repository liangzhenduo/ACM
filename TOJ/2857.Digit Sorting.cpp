#include <iostream>
using namespace std;

    int change(int m)
    {
        int sorting[7];
        sorting[0]=m%10;
        sorting[1]=(m/10)%10;
        sorting[2]=(m/100)%10;
        sorting[3]=(m/1000)%10;
        sorting[4]=(m/10000)%10;
        sorting[5]=m/100000;
        for(int i=6;i>0;i--)
        {
            int maximum=sorting[0];
            int maxI=0;
            for(int j=1;j<=i;j++)
                if(maximum<sorting[j])
                {
                    maximum=sorting[j];
                    maxI=j;
                }
            if(maxI!=i)
            {
                sorting[maxI]=sorting[i];
                sorting[i]=maximum;
            }
        }
        int result=100000*sorting[0]+10000*sorting[1]+1000*sorting[2]
                    +100*sorting[3]+10*sorting[4]+sorting[5];
        return result;
    }

int main()
{
    int n,m=0;
    int input[51],output[51];
    while(cin >>n)
    {
        if(n==0)
            break;
        int s=0;
        for(int j=0;j<n;j++)
            cin >>input[j];
        for(int i=0;i<n;i++)
        {
            m=input[i];
            output[i]=change(m);
            if(output[i]>=s)
                s=output[i];
        }
        cout <<s<<endl;
    }
    return 0;
}
