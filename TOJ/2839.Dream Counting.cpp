#include <iostream>
using namespace std;
int main()
{
    int a,b;
    while(cin >>a>>b)
    {
        int c[10]={0};
        for(int i=a;i<=b;i++)
        {
            int k=i;
            while(k>0)
            {
                c[k% 10]++;
                k/=10;
            }
        }
        for(int j=0;j<9;j++)
            cout <<c[j]<<" ";
        cout <<c[9]<<endl;
    }
    return 0;
}
