#include <iostream>
using namespace std;
char labyrinth[1001][1001];
int X,Y;

	int length(int R,int C)
	{
		int k,l,dX,dY;
		if(labyrinth[R][C]=='.')
		{
			labyrinth[R][C]='*';
			dX=C;
 			dY=R;
			k=0;
			l=length(R-1,C);
			if(l>k)
			{
				dX=X;
				dY=Y;
				k=l;
			}
			l=length(R+1,C);
			if(l>k)
			{
				dX=X;
				dY=Y;
				k=l;
			}
			l=length(R,C-1);
			if(l>k)
			{
				dX=X;
				dY=Y;
				k=l;
			}
			l=length(R,C+1);
			if(l>k)
			{
				dX=X;
				dY=Y;
				k=l;
			}
			X=dX;
			Y=dY;
			return ++k;
		}
		return 0;
	}

int main()
{
	int n,x,y;
	cin >>n;
	while(n--)
	{
		cin >>x>>y;
		for(int i=0;i<y;i++)
			cin >>labyrinth[i];
		int r=1,c=1;
		while(labyrinth[r][c]=='#')
		{
			if(r<y-1)
  				r++;
  			else
			{
				r=1;
				c++;
			}
		}
		length(r,c);
		for(int i=0;i<y;i++)
 			for(int j=0;j<x;j++)
  				if(labyrinth[i][j]=='*')
   					labyrinth[i][j]='.';
		cout <<"Maximum rope length is "<<length(Y,X)-1<<"."<<endl;
	}
	return 0;
}
