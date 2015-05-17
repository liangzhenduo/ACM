#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        char n[100001];
        cin >>n;
        int l=strlen(n),sum=0,j;
        for(int i=0;i<l;i++)
            sum+=n[i]-48;
        sum%=10;
        if(n[l-1]-48<sum)
            n[l-1]+=10-sum;
        else
        {
            n[l-1]=57;
            sum=0;
            for(j=l-1;j>=0;j--)
                if(n[j]!=57)
                    break;
                else
                    n[j]=48;
            if(j==-1)
            {
                n[l-1]=57;
                cout <<1<<n<<endl;
                continue;
            }
            n[j]++;
            for(int i=0;i<=j;i++)
                sum+=n[i]-48;
            sum%=10;
            if(sum)
                n[l-1]+=10-sum;
        }
        cout <<n<<endl;
    }
    return 0;
}
