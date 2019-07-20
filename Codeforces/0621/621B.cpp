#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a[2001],b[2001];
int main(){
	int n,i,j,x,y;
	long long ans;
	while(scanf("%d",&n)!=EOF){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			a[1000+x-y]++,b[x+y]++;
		}
		for(ans=0,i=0;i<2001;i++)
			ans+=(a[i]*(a[i]-1)/2+b[i]*(b[i]-1)/2);
		cout<<ans<<endl;
	}
}