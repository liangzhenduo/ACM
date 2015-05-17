#include <iostream>
using namespace std;
int main()
{
    int t,n,m,a,b;
    cin >>t;
    while(t--)
    {
        cin >>n>>m;
        int room[101],used[101],k=0,ma,mi;
        for(int i=1;i<=n;i++)
        {
            room[i]=1;
            used[i]=i;
        }
        while(m--)
        {
            cin >>a>>b;
            if(used[a]==used[b])
                continue;
            a>b?(ma=a,mi=b):(ma=b,mi=a);
            int num=used[ma];
            for(int j=1;j<=n;j++)
                if(used[j]==num)
                {
                    used[j]=used[mi];
                    room[j]=0;
                }
        }
        for(int i=1;i<=n;i++)
            if(room[i])
                k++;
        cout <<k<<endl;
    }
    return 0;
}
