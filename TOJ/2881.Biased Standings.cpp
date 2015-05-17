#include <cstdio>
#include <algorithm>
int main(){
    int t,n;
    long long i,j,rank[100001];
    char name[21];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%s %lld",name,&rank[i]);
        std::sort(rank+1,rank+n+1);
        for(j=0,i=1;i<=n;i++)
            j+=(rank[i]>i?rank[i]-i:i-rank[i]);
        printf("%lld\n",j);
    }
}
