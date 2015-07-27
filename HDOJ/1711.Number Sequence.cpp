#include <cstdio>
int a[1000001],b[10001],n,m,next[10001];
void nxt(){
    next[0]=next[1]=0;
    for(int i=1;i<m;i++){
        int j=next[i];
        while(j&&b[i]!=b[j])
            j=next[j];
        next[i+1]=b[i]==b[j]?j+1:0;
    }
}
int kmp(){
    nxt();
    for(int i=0,j=0;i<n;i++){
        while(j&&b[j]!=a[i])
            j=next[j];
        if(b[j]==a[i])
            j++;
        if(j==m)
            return i-m+2;
    }
    return -1;
}
int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<m;i++)
            scanf("%d",&b[i]);
        printf("%d\n",kmp());
    }
}
