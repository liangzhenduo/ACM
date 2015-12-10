#include <cstdio>
#include <cstring>
#include <algorithm>
int main(){
	int n,c,ans,a[100001];
	while(scanf("%d",&n)!=EOF){
		ans=0;
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++){
			scanf("%d",&c);
			a[c]=a[c-1]+1;
			ans=std::max(ans,a[c]);
		}
		printf("%d\n",n-ans);
	}
}