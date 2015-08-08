#include <cstdio>
#include <cstring>
int fa[10001],cnt[10001],step[10001];
int fin(int x){
    int tmp=fa[x];
    if(x!=fa[x]) fa[x]=fin(fa[x]);
    step[x]+=step[tmp];
    return fa[x];
}
void uni(int x,int y){
    x=fin(x),y=fin(y);
    if(x==y) return;
    step[x]++;
    fa[x]=y;
}
int main(){
    int t,k=0,n,q,i,a,b;
    scanf("%d",&t);
    char s[2];
    while(t--){
        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++) fa[i]=i,cnt[i]=1,step[i]=0;
        printf("Case %d:\n",++k);
        while(q--){
            scanf("%s",&s);
            if(s[0]=='T'){
                scanf("%d%d",&a,&b);
                cnt[fin(b)]+=cnt[fin(a)];
                uni(a,b);
            }
            else{
                scanf("%d",&a);
                b=fin(a);
                printf("%d %d %d\n",b,cnt[b],step[a]);
            }
        }
    }
}
