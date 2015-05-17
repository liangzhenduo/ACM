#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n,num[10001];
    num[1]=1;
    for(int i=2,j=1;i<10001;i++)
    {
        j*=i;
        while(j%10==0)
            j/=10;
        j%=100000;
        num[i]=j%10;
    }
    while(cin >>n&&n)
        cout <<setw(5)<<n<<" -> "<<num[n]<<endl;
    return 0;
}
