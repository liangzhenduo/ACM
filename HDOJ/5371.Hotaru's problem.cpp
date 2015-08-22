#include <cstdio>
#include <algorithm>
const int maxn=200005;
int a[maxn],p[maxn];
void manacher(int n){
    int mx=0,id=0,i;
    for(i=0;i<n;i++){
        p[i]=i>mx?1:std::min(p[2*id-i],mx-i);
        while(i>=p[i]&&i+p[i]<n&&a[i+p[i]]==a[i-p[i]]) p[i]++;
        if(i+p[i]>mx)
            mx=p[i]+i,id=i;
    }
}
int main(){
    int t,n,cas=0,i,j,ans,len;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        len=0;
        a[len++]=-1;
        for(i=1;i<=n;i++){
            scanf("%d",&a[len++]);
            a[len++]=-1;
        }
        manacher(len);
        for(ans=1,i=2;i<len;i+=2)
            for(j=p[i];j>ans;j-=2)
                if(p[i+j-1]>=j){
                    ans=j;
                    break;
                }
        printf("Case #%d: %d\n",++cas,ans/2*3);
    }
}