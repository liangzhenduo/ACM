#include <iostream>
using namespace std;

    void step(int board[10][10],int k,int i,int j)
    {
        if(!board[i][j]&&i>0&&j>0&&i<9&&j<9)
            board[i][j]=k+1;
    }

int main()
{
    char a[3],b[3];
    while(cin >>a>>b)
    {
        int board[10][10]={0};
        board[a[1]-48][a[0]-96]=1;
        for(int k=1;!board[b[1]-48][b[0]-96];k++)
            for(int i=1;i<9;i++)
                for(int j=1;j<9;j++)
                    if(board[i][j]==k)
                    {
                        step(board,k,i-1,j-2);
                        step(board,k,i-2,j-1);
                        step(board,k,i-1,j+2);
                        step(board,k,i-2,j+1);
                        step(board,k,i+1,j-2);
                        step(board,k,i+2,j-1);
                        step(board,k,i+1,j+2);
                        step(board,k,i+2,j+1);
                    }
        cout <<"To get from "<<a<<" to "<<b<<" takes "<<board[b[1]-48][b[0]-96]-1<<" knight moves."<<endl;
    }
    return 0;
}
