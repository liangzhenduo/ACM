#include <cstdio>
int sp[100001],n,m;
int part(int mid){
    int i,cnt,sum;
    for(cnt=1,sum=i=0;i<n;i++){
        if(sp[i]>mid)
            continue;
        sum+=sp[i];
        if(sum>mid)
            sum=sp[i],cnt++;
    }
    return cnt;
}
int bs(int l,int r){
    int mid=l+(r-l)/2;
    if(l>=r) return r;
    int cnt=part(mid);
    if(cnt<=m) return bs(l,mid-1);
    return bs(mid+1,r);
}
int main(){
    int i,j,sum,maxn;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(sum=maxn=i=0;i<n;i++){
            scanf("%d",&sp[i]);
            sum+=sp[i];
            maxn=maxn<sp[i]?sp[i]:maxn;
        }
        printf("%d\n",bs(maxn,sum));
    }
}
