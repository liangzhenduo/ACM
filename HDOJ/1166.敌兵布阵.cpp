#include <cstdio>
#include <cstring>
int camp[50001];
struct Node{
    int l,r,w;
}node[200001];
void build(int l,int r,int s){
    node[s].l=l,node[s].r=r;
    if(l==r){
        node[s].w=camp[l];
        return;
    }
    int mid=l+(r-l)/2;
    build(l,mid,2*s);
    build(mid+1,r,2*s+1);
    node[s].w=node[2*s].w+node[2*s+1].w;
}
void update(int a,int b,int s){
    if(node[s].l==a&&node[s].r==a){
        node[s].w+=b;return;
    }
    int mid=(node[s].l+(node[s].r-node[s].l)/2);
    if(a<=mid)
        update(a,b,2*s);
    else
        update(a,b,2*s+1);
    node[s].w=node[2*s].w+node[2*s+1].w;
}
int query(int l,int r,int s){
    if(node[s].l==l&&node[s].r==r)
        return node[s].w;
    int mid=(node[s].l+(node[s].r-node[s].l)/2);
    if(r<=mid)
        return query(l,r,2*s);
    else if(l>mid)
        return query(l,r,2*s+1);
    else
        return query(l,mid,2*s)+query(mid+1,r,2*s+1);
}
int main(){
    int c=0,t,n,a,b;
    char opr[6];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&camp[i]);
        printf("Case %d:\n",++c);
        memset(node,0,sizeof(node));
        build(1,n,1);
        while(scanf("%s",opr)&&opr[0]!='E'){
            scanf("%d%d",&a,&b);
            if(opr[0]=='A')
                update(a,b,1);
            else if(opr[0]=='S')
                update(a,-b,1);
            else
                printf("%d\n",query(a,b,1));
        }
    }
}
