#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
class BichromeBoard{	
public:
	string ableToDraw(vector <string> board){
		int m=board[0].size();
		int n=board.size();
		int i,j,b,w;
		bool flag=1;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(board[i][j]!='?'){
					if(board[i][j]=='B')b=(i+j)%2,w=(i+j+1)%2;
					else if(board[i][j]=='W')w=(i+j)%2,b=(i+j+1)%2;
					break;
				}
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if((board[i][j]=='B'&&(i+j)%2!=b)||(board[i][j]=='W'&&(i+j)%2!=w)){
					flag=0;
					break;
				}
		if(flag) return "Possible";
		else return "Impossible";
	}
};