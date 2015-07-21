#include <cstdio>
#include <algorithm>
struct Edge{
    int u,v,w,o;
}edge[4950];
int root[101],sum;
bool cmp(Edge p,Edge q){
    return p.w<q.w;
}
int fin(int x){
    return root[x]-x?root[x]=fin(root[x]):x;
}
void uni(Edge e){
    int x=fin(e.u),y=fin(e.v);
    if(x-y){
        root[x]=y;
        sum+=e.w;
    }
}
int main(){
    int n,m,i;
    while(scanf("%d",&n)&&n){
        m=n*(n-1)/2;
        for(i=1;i<=n;i++)
            root[i]=i;
        for(i=0;i<m;i++){
            scanf("%d%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w,&edge[i].o);
            edge[i].w=edge[i].o?0:edge[i].w;
        }
        std::sort(edge,edge+m,cmp);
        for(sum=0,i=0;i<m;i++)
            uni(edge[i]);
        printf("%d\n",sum);
    }
}
