#include <iostream>
using namespace std;

    void dfs(int w,int h,int x,int y,int marine[51][51])
    {
        marine[x][y]=0;
        for(int dx=-1;dx<=1;dx++)
            for(int dy=-1;dy<=1;dy++)
            {
                int nx=x+dx,ny=y+dy;
                if(0<=nx&&nx<h&&0<=ny&&ny<=w&&marine[nx][ny]==1)
                    dfs(w,h,nx,ny,marine);
            }
        return;
    }

int main()
{
    int w,h;
    while(cin >>w>>h&&w+h)
    {
        int marine[51][51]={0},k=0;
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                cin >>marine[i][j];
        for(int x=0;x<h;x++)
            for(int y=0;y<w;y++)
                if(marine[x][y]==1)
                {
                    dfs(w,h,x,y,marine);
                    k++;
                }
        cout <<k<<endl;
    }
    return 0;
}
