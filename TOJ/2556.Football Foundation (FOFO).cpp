#include <iostream>
using namespace std;
int main()
{
    int x,y,n;
    while(cin >>x>>y>>n)
    {
        if(x==0&&y==0&&n==0)
            break;
        const int p=x+2,q=y+2,r=x*y;
        char grid[p][q];
        for(int i=0;i<p;i++)
            for(int j=0;j<q;j++)
                grid[i][j]='O';
        for(int i=1;i<p-1;i++)
            for(int j=1;j<q-1;j++)
                cin >>grid[i][j];
        int u=1,v=n,h=0;
        int U[r],V[r];
        for(int k=0;;k++)
        {
            U[k]=u;
            V[k]=v;
            for(int l=0;l<k;l++)
                if(u==U[l]&&v==V[l])
                {
                    cout <<l<<" step(s) before a loop of "<<k-l<<" step(s)"<<endl;
                    h++;
                    break;
                }
            if(h==1)
                break;
            if(grid[u][v]=='O')
            {
                cout <<k<<" step(s) to exit"<<endl;
                break;
            }
            else if(grid[u][v]=='E')
                v++;
            else if(grid[u][v]=='W')
                v--;
            else if(grid[u][v]=='S')
                u++;
            else if(grid[u][v]=='N')
                u--;
        }
    }
    return 0;
}

