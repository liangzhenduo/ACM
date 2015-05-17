#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int len[100],use[100],flag,n,m,l;
void dfs(int idx,int crt,int cnt){
    if(cnt==m){
        flag=1;
        return;
    }
    else if(crt==l) dfs(0,0,cnt+1);
    else
        for(int pre=-1,i=idx;i<n;i++)
            if(!use[i]&&len[i]!=pre&&crt+len[i]<=l){
                use[i]=1;
                pre=len[i];
                dfs(idx+1,crt+len[i],cnt);
                use[i]=0;
                if(idx==0||flag) return;
            }
}
bool cmp(int p,int q){
    return p>q;
}
int main(){
    int i,sum;
    while(scanf("%d",&n)&&n){
        memset(use,0,sizeof(use));
        for(sum=i=0;i<n;i++){
            scanf("%d",&len[i]);
            sum+=len[i];
            if(len[i]>50) n--,sum-=len[i--];
        }
        if(!n) {puts("0");continue;}
        sort(len,len+n,cmp);
        for(flag=0,l=len[0];l<=sum;l++){
            if(sum%l) continue;
            m=sum/l;
            dfs(0,0,0);
            if(flag) break;
        }
        printf("%d\n",l);
    }
}
