#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
const int maxn=10005;
int hsh[maxn],cnt;
struct Node{
    int v;
    char op[9];
}in[maxn];
int sum[4*maxn];
void update(int l,int r,int m,int value,int pos){
    if(l==r){
        sum[pos]=value;
        return;
    }
    int mid=l+(r-l)/2;
    if(m<=mid)
        update(l,mid,m,value,2*pos);
    else
        update(mid+1,r,m,value,2*pos+1);
    sum[pos]=sum[2*pos]+sum[2*pos+1];
    return;
}
int query(int l,int r,int value,int pos){
    if(l==r) return l;
    int mid=l+(r-l)/2;
    if(sum[2*pos]>=value)
        return query(l,mid,value,2*pos);
    else
        return query(mid+1,r,value-sum[2*pos],2*pos+1);
}
int main(){
    int n,cas=0,i;
    while(scanf("%d",&n)!=EOF){
        cnt=0;
        queue<int>q;
        memset(sum,0,sizeof(sum));
        for(i=0;i<n;i++){
            scanf("%s",in[i].op);
            if(in[i].op[0]=='i'){
                scanf("%d",&in[i].v);
                hsh[cnt++]=in[i].v;
            }
        }
        sort(hsh,hsh+cnt);
        cnt=unique(hsh,hsh+cnt)-hsh;
        printf("Case #%d:\n",++cas);
        for(i=0;i<n;i++){
            if(in[i].op[0]=='i'){
                int e=lower_bound(hsh,hsh+cnt,in[i].v)-hsh+1;
                q.push(e);
                update(1,cnt,e,1,1);
            }
            else if(in[i].op[0]=='o'){
                int e=q.front();
                q.pop();
                update(1,cnt,e,0,1);
            }
            else{
                int e=query(1,cnt,sum[1]/2+1,1);
                printf("%d\n",hsh[e-1]);
            }
        }
    }
}
