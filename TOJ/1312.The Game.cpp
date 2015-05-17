#include <iostream>
using namespace std;
int main()
{
    int o;
    cin >>o;
    int board[21][21];
    for(int m=0;m<21;m++)
        for(int n=0;n<21;n++)
            board[m][n]=0;
    for(int k=0;k<o;k++)
    {
        for(int m=1;m<20;m++)
            for(int n=1;n<20;n++)
                cin >>board[m][n];
        int l=0,i,j;
        for(i=1;i<20;i++)
        {
            for(j=1;j<20;j++)
            {
                if(board[i][j]==1&&(
                    (board[i][j+1]==1&&board[i][j+2]==1&&board[i][j+3]==1&&board[i][j+4]==1&&board[i][j+5]!=1&&board[i][j-1]!=1)||
                    (board[i+1][j]==1&&board[i+2][j]==1&&board[i+3][j]==1&&board[i+4][j]==1&&board[i+5][j]!=1&&board[i-1][j]!=1)||
                    (board[i+1][j+1]==1&&board[i+2][j+2]==1&&board[i+3][j+3]==1&&board[i+4][j+4]==1&&board[i+5][j+5]!=1&&board[i-1][j-1]!=1)||
                    (board[i-1][j+1]==1&&board[i-2][j+2]==1&&board[i-3][j+3]==1&&board[i-4][j+4]==1&&board[i-5][j+5]!=1&&board[i+1][j-1]!=1)))
                    {
                        cout <<"1"<<endl;
                        cout <<i<<" "<<j<<endl;
                        l=1;
                        break;
                    }
                else if(board[i][j]==2&&(
                    (board[i][j+1]==2&&board[i][j+2]==2&&board[i][j+3]==2&&board[i][j+4]==2&&board[i][j+5]!=2&&board[i][j-1]!=2)||
                    (board[i+1][j]==2&&board[i+2][j]==2&&board[i+3][j]==2&&board[i+4][j]==2&&board[i+5][j]!=2&&board[i-1][j]!=2)||
                    (board[i+1][j+1]==2&&board[i+2][j+2]==2&&board[i+3][j+3]==2&&board[i+4][j+4]==2&&board[i+5][j+5]!=2&&board[i-1][j-1]!=2)||
                    (board[i-1][j+1]==2&&board[i-2][j+2]==2&&board[i-3][j+3]==2&&board[i-4][j+4]==2&&board[i-5][j+5]!=2&&board[i+1][j-1]!=2)))
                    {
                        cout <<"2"<<endl;
                        cout <<i<<" "<<j<<endl;
                        l=1;
                        break;
                    }
            }
            if(l==1)
                break;
        }
        if(l==0)
            cout <<"0"<<endl;
    }
    return 0;
}
