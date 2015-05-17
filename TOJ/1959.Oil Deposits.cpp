#include <iostream>
using namespace std;

    void dfs(int n,int m,int x,int y,char oil[100][100])
    {
        oil[x][y]='*';
        for(int dx=-1;dx<=1;dx++)
            for(int dy=-1;dy<=1;dy++)
            {
                int nx=x+dx,ny=y+dy;
                if(0<=nx&&nx<m&&0<=ny&&ny<=n&&oil[nx][ny]=='@')
                    dfs(n,m,nx,ny,oil);
            }
        return;
    }

int main()
{
    int m,n;
    while(cin >>m>>n&&m)
    {
        char oil[100][100]={'*'};
        int k=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                cin >>oil[i][j];
        for(int x=0;x<m;x++)
            for(int y=0;y<n;y++)
                if(oil[x][y]=='@')
                {
                    dfs(n,m,x,y,oil);
                    k++;
                }
        cout <<k<<endl;
    }
    return 0;
}
