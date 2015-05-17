#include <cstdio>
int fa[10001];
int fin(int i){
    if(fa[i]!=i) return fa[i]=fin(fa[i]);
    return i;
}
void uni(int a,int b){
    int x=fin(a),y=fin(b);
    if(x-y)
        fa[x]=y;
}
int main(){
    int n,m,k,i,a,b;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        for(i=0;i<n;i++)
            fa[i]=i;
        while(m--){
            scanf("%d%d",&a,&b);
            uni(a,b);
        }
        while(k--){
            scanf("%d%d",&a,&b);
            if(fin(a)-fin(b)) puts("NO");
            else puts("YES");
        }
    }
}
