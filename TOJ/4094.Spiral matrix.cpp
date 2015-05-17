#include <iostream>
using namespace std;
int mat[202][202]={0};
int main()
{
    int n,m;
    while(cin >>n>>m)
    {
        int x=1,y=1,k=1,i,j;
        for(i=1;i<=n+1;i++)
            for(j=1;j<=m+1;j++)
                mat[i][j]=0;
        while(k<=n*m)
        {
            mat[x][y]=k++;
            if(mat[x][y+1]==0&&(mat[x-1][y]!=0||x==1)&&y<m)
                y++;
            else if(mat[x+1][y]==0&&x<n)
                x++;
            else if(mat[x][y-1]==0&&y>1)
                y--;
            else if(mat[x-1][y]==0&&x>1)
                x--;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<m;j++)
                cout <<mat[i][j]<<" ";
            cout <<mat[i][j]<<endl;
        }
    }
    return 0;
}
