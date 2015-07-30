#include <cstdio>
#include <cstring>
#include <algorithm>
int stu[200001];
struct Node{
    int l,r,w;
}node[800001];
void build(int l,int r,int s){
    node[s].l=l,node[s].r=r;
    if(l==r){
        node[s].w=stu[l];
        return;
    }
    int mid=l+(r-l)/2;
    build(l,mid,2*s);
    build(mid+1,r,2*s+1);
    node[s].w=std::max(node[2*s].w,node[2*s+1].w);
}
void update(int a,int b,int s){
    if(node[s].l==a&&node[s].r==a){
        node[s].w=b;return;
    }
    int mid=(node[s].l+(node[s].r-node[s].l)/2);
    if(a<=mid)
        update(a,b,2*s);
    else
        update(a,b,2*s+1);
    node[s].w=std::max(node[2*s].w,node[2*s+1].w);
}
int query(int l,int r,int s){
    if(node[s].l==l&&node[s].r==r)
        return node[s].w;
    int mid=(node[s].l+(node[s].r-node[s].l)/2);
    if(r<=mid)
        return query(l,r,2*s);
    if(l>mid)
        return query(l,r,2*s+1);
    if(l<=mid&&r>mid)
        return std::max(query(l,mid,2*s),query(mid+1,r,2*s+1));
    return 0;
}
int main(){
    int n,m,a,b;
    char opr[2];
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(node,0,sizeof(node));
        for(int i=1;i<=n;i++)
            scanf("%d",&stu[i]);
        build(1,n,1);
        while(m--){
            scanf("%s%d%d",opr,&a,&b);
            if(opr[0]=='U')
                update(a,b,1);
            else
                printf("%d\n",query(a,b,1));
        }
    }
}
