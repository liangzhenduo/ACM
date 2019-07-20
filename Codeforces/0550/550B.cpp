#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    int n,l,r,x,i,j,k,m,ma,mi,sum,ans;
    int s[16],f[16];
    while(scanf("%d%d%d%d",&n,&l,&r,&x)!=EOF){
        for(i=0;i<n;i++) scanf("%d",&s[i]);
        j=1<<n;
        for(ans=i=0;i<j;i++){
            for(k=i,m=0;m<n;k/=2,m++)
                f[m]=k%2;
            for(sum=k=0,mi=100000001,ma=0;k<n;k++)
                if(f[k]){
                    sum+=s[k];
                    ma=s[k]>ma?s[k]:ma;
                    mi=s[k]<mi?s[k]:mi;
                }
            if(ma-mi>=x&&sum>=l&&sum<=r) ans++;
        }
        printf("%d\n",ans);
    }
}
