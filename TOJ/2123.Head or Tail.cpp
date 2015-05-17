#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin >>n&&n!=0)
    {
        int game[10000];
        int i=0,j=0,k=0;
        for(i=0;i<n;i++)
            cin >>game[i];
        for(j=0;j<n;j++)
            if(game[j]==0)
                k++;
        cout <<"Mary won "<<k<<" times and John won "<<n-k<<" times"<<endl;
    }
  return 0;
}
