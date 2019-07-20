#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct Child{
	int v,d,p,l;
}child[4001];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d%d%d",&child[i].v,&child[i].d,&child[i].p);
		vector<int> ans;
		for(int i=0;i<n;i++){
			if(child[i].p<0) continue;
			ans.push_back(i+1);
			for(int j=i+1,k=child[i].v;j<n;j++){
				child[j].l=0;
				if(child[j].p>=0){
					child[j].p-=max(k--,0);
					child[j].l=1;
				}
			}
			for(int j=i+1,k=0;j<n;j++){
				if(child[j].p>=0)
					child[j].p-=k;
				if(child[j].p<0&&child[j].l)
					k+=child[j].d;
			}
		}
		printf("%lu\n1",ans.size());
		for(int i=1;i<ans.size();i++)
			printf(" %d",ans[i]);
		puts("");
	}
}