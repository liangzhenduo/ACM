#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100005],v[100005];
int main(){
	int t,n,i,j,k,ans,cas=0;
	scanf("%d",&t);
	while(t--){
		memset(v,0,sizeof(v));
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			v[a[i]]++;
		}
		sort(a,a+n);
		for(ans=1,j=a[n-2];j>1;j--){
			for(k=0,i=j;i<=a[n-1];i+=j){
				if(!v[i]) continue;
				k+=v[i];
				if(k>1){
					ans=j;break;
				}
			}
			if(ans>1) break;
		}
		printf("Case #%d: %d\n",++cas,ans);
	}
}