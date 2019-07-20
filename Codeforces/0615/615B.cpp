#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define pii pair<int,int>
int s[100005];
int l[100005];
pii p[200005];
bool cmp(pii p,pii q){
	if(p.first==q.first) return p.second<q.second;
	return p.first<q.first;
}
int main(){
	int n,m,u,v;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(s,0,sizeof(s));
		memset(l,0,sizeof(l));
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			if(u>v) swap(u,v);
			s[u]++,s[v]++;
			p[i].first=u,p[i].second=v;
		}
		sort(p+1,p+m+1,cmp);
		long long ans=s[1];
		for(int i=1;i<=m;i++){
			l[p[i].second]=max(l[p[i].first]+1,l[p[i].second]);
			if(ans<(1LL+l[p[i].second])*s[p[i].second])
				ans=(1LL+l[p[i].second])*s[p[i].second];
		}
		cout<<ans<<endl;
	}
}