#include <iostream>
using namespace std;
int main()
{
	int n,m,c,i,j=0,a[21][2],k,index,flag,max;
	while(cin >>n>>m>>c&&n+m+c)
	{
		cout <<"Sequence "<<++j<<endl;
		for(i=1;i<=n;i++)
		{
			cin >>a[i][0];
			a[i][1]=0;
		}
		k=0,flag=0,max=0;
		while(m--)
		{
			cin >>index;
			if(a[index][1])
			{
				a[index][1]=0;
				k-=a[index][0];
			}
			else
			{
				a[index][1]=1;
				k+=a[index][0];
			}
			if(k>max&&k<=c)
				max=k;
			if(k>c)
				flag=1;
		}
		if(flag)
			cout <<"Fuse was blown."<<endl<<endl;
		else
			cout <<"Fuse was not blown."<<endl<<"Maximal power consumption was "<<max<<" amperes."<<endl<<endl;
	}
	return 0;
}
