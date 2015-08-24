#include <cstdio>
long long a[100005],l[100005],r[100005],ans;
int main(){
    int d1,d2,n,i,j;
    while(~scanf("%d%d%d",&n,&d1,&d2)){
        for(i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        l[0]=l[1]=1;
        for(i=2;i<=n;i++){
            if(a[i]==a[i-1]+d1)
                l[i]=l[i-1]+1;
            else
                l[i]=1;
        }
        r[n+1]=r[n]=1;
        for(i=n-1;i>0;i--){
            if(a[i]==a[i+1]-d2)
                r[i]=r[i+1]+1;
            else
                r[i]=1;
        }
        for(ans=0,i=1;i<=n;i++){
            if(d1==d2)
                ans+=l[i];
            else
                ans+=r[i]*l[i];
        }
        printf("%lld\n",ans);
    }
}