#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,k,sum,len[65],used[65];
bool dfs(int cur,int idx,int cnt){
    if(k*cnt==sum)
        return 1;
    for(int i=idx;i<n;i++){
        if(used[i]||(i&&!used[i-1]&&len[i]==len[i-1])) continue;
        if(cur+len[i]==k){
            used[i]=1;
            if(dfs(0,0,cnt+1)) return 1;
            used[i]=0;
            return 0;
        }
        else if(cur+len[i]<k){
            used[i]=1;
            if(dfs(cur+len[i],i+1,cnt)) return 1;
            used[i]=0;
            if(cur==0) return 0;
        }
    }
    return 0;
}

int main(){
    while(scanf("%d",&n)&&n){
        for(int i=sum=0;i<n;i++){
            scanf("%d",&len[i]);
            sum+=len[i];
        }
        sort(len,len+n);
        reverse(len,len+n);
        for(k=len[0];k<sum;k++){
            if(sum%k) continue;
            memset(used,0,sizeof(used));
            if(dfs(0,0,0)) break;
        }
        printf("%d\n",k);
    }
}
