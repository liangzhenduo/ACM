#include <cstdio>
#include <cstring>
int bug[4001];
int fin(int x){
    return bug[x]?bug[x]=fin(bug[x]):x;
}
void uni(int p,int q){
    int x=fin(p),y=fin(q);
    if(x-y) bug[x]=y;
}
int main(){
    int t,n,m,i,j,a,b,flag;
    scanf("%d",&t);
    for(j=1;j<=t;j++){
        memset(bug,0,sizeof(bug));
        scanf("%d%d",&n,&m);
        for(flag=i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            uni(a,b+n),uni(b,a+n);
            if(fin(a)==fin(a+n)||fin(b)==fin(b+n)) flag=1;
        }
        printf("Scenario #%d:\n",j);
        puts(flag?"Suspicious bugs found!\n":"No suspicious bugs found!\n");
    }
}
