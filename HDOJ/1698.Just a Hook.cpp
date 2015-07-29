#include <cstdio>
#include <cstring>
struct Node{
    int l,r,w;
}node[400000];
int z;
void build(int l,int r,int s){
    node[s].l=l,node[s].r=r,node[s].w=1;
    if(l==r) return;
    int mid=l+(r-l)/2;
    build(l,mid,2*s);
    build(mid+1,r,2*s+1);
}
void update(int l,int r,int s){
    if(node[s].w==z) return;
    if(node[s].l==l&&node[s].r==r){
        node[s].w=z;return;
    }
    if(node[s].w)
        node[2*s].w=node[2*s+1].w=node[s].w;
    node[s].w=0;
    int mid=(node[s].l+(node[s].r-node[s].l)/2);
    if(mid>=l&&mid<r)
        update(l,mid,2*s),update(mid+1,r,2*s+1);
    else
        update(l,r,2*s+(mid<l));
}
int sum(int s){
    if(node[s].w)
        return (node[s].r-node[s].l+1)*node[s].w;
    else
        return sum(2*s)+sum(2*s+1);
}
int main(){
    int c=0,t,n,q,x,y;
    scanf("%d",&t);
    while(t--){
        memset(node,0,sizeof(node));
        scanf("%d%d",&n,&q);
        build(1,n,1);
        while(q--){
            scanf("%d%d%d",&x,&y,&z);
            update(x,y,1);
        }
        printf("Case %d: The total value of the hook is %d.\n",++c,sum(1));
    }
}
