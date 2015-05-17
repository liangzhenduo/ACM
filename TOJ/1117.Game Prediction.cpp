#include <iostream>
using namespace std;
int main()
{
    int m,n,pip,cas=0;
    while(cin >>m>>n&&m+n)
    {
        cas++;
        int ans=0,card[1001]={0};
        for(int i=0;i<n;i++)
        {
            cin >>pip;
            card[pip]=1;
        }
        for(int i=m*n;i>0&&n;i--)
        {
            if(card[i]==1)
            {
                ans++;
                n--;
            }
            else if(!card[i])
            {
                for(int j=i-1;;j--)
                    if(card[j]==1)
                    {
                        card[j]=-1;
                        break;
                    }
                n--;
            }
        }
        cout <<"Case "<<cas<<": "<<ans<<endl;
    }
    return 0;
}

