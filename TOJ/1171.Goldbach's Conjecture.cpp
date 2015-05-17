#include <iostream>
using namespace std;
int num[1000000];
int main()
{
    int n,i,j;
    for(i=2;i<1001;i++)
        if(num[i]==0)
            for(j=i*i;j<1000001;j+=i)
                num[j]=1;
    while(cin >>n&&n>0)
    {
        for(i=2;i<n;i++)
            if(num[i]==0&&num[n-i]==0)
                break;
        cout <<n<<" = "<<i<<" + "<<n-i<<endl;
    }
    return 0;
}
