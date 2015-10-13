#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
	int n,a[50]={0},b[50]={0},c[51],i,j,ans1,ans2;
	while(scanf("%d",&n)!=EOF){
		for(i=1;i<n;i++){
			scanf("%d",&j);
			a[i]=j+a[i-1];
		}
		for(i=1;i<n;i++){
			scanf("%d",&j);
			b[i]=j+b[i-1];
		}
		for(i=0;i<n;i++){
			scanf("%d",&c[i]);
		}
		for(i=0,ans1=ans2=10000;i<n;i++){
			int tmp=a[i]+b[n-1]-b[i]+c[i];
			if(tmp<max(ans1,ans2)) ans1>ans2?ans1=tmp:ans2=tmp;
		}
		printf("%d\n",ans1+ans2);
	}
	
}