#include <cstdio>
int fa[1001];
int fi(int c){
    int i=c,j=c,temp;
    while(i!=fa[i])
        i=fa[i];
    while(j!=i){
        temp=fa[j];
        fa[j]=i;
        j=temp;
    }
    return i;
}
int main(){
    int n,m,a,b,i,k;
    while(scanf("%d",&n)&&n){
        scanf("%d",&m);
        for(k=n-1,i=1;i<=n;i++)
            fa[i]=i;
        while(m--){
            scanf("%d%d",&a,&b);
            int p=fi(a),q=fi(b);
            if(p!=q){
                fa[p]=q;
                k--;
            }
        }
        printf("%d\n",k);
    }
}
