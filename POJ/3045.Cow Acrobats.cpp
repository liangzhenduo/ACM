#include <cstdio>
#include <vector>
#include <algorithm>
#define P pair<int,int>
using namespace std;
bool cmp(P p,P q){
    return (p.first+p.second)<(q.first+q.second);
}
int main(){
    int n,i,w,s,sum,ans;
    while(scanf("%d",&n)!=EOF){
        vector<P> cow;
        for(i=0;i<n;i++){
            scanf("%d%d",&w,&s);
            cow.push_back(make_pair(w,s));
        }
        sort(cow.begin(),cow.end(),cmp);
        for(sum=cow[0].first,ans=-cow[0].second,i=1;i<n;i++){
            ans=max(sum-cow[i].second,ans);
            sum+=cow[i].first;
        }
        printf("%d\n",ans);
    }
}
