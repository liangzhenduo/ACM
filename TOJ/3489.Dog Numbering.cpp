#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int t,n,m[51];
	cin >>t;
	while(t--)
	{
		cin >>n;
		for(int i=0;i<n;i++)
			cin >>m[i];
		sort(m,m+n);
		long long k=1;
		for(int j=0;j<n;j++)
			k=(k*(m[j]-j))%1000000007;
		cout <<k<<endl;
	}
	return 0;
}
