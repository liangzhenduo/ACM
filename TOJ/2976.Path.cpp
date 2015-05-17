#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n,m,a,b,c;
    while(cin >>n>>m&&n+m)
    {
        int cross[101][101],k[101],used[101]={0,1};
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cross[i][j]=65536;
        while(m--)
        {
             cin >>a>>b>>c;
             if(cross[a][b]>c)
                 cross[a][b]=cross[b][a]=c;
        }
        for(int i=1;i<=n;i++)
            k[i]=cross[1][i];
        for(int i=2;i<=n;i++)
        {
            int t=65536,l=1;
            for(int j=1;j<=n;j++)
                if(!used[j]&&k[j]<t)
                {
                    t=k[j];
                    l=j;
                }
            used[l]=1;
            for(int j=1;j<=n;j++)
                if(!used[j]&&t+cross[l][j]<k[j])
                    k[j]=t+cross[l][j];
        }
        cout <<k[n]<<endl;
    }
    return 0;
}
