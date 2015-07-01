#include <cstdio>
using namespace std;
int main(){
    int n,k,i,j,l,ans,c[100001];
    while(scanf("%d%d",&n,&k)!=EOF){
        for(ans=n-1,i=0;i<k;i++){
            scanf("%d%d",&j,&c[0]);
            ans+=j-1;
            for(l=1;l<j;l++)
                scanf("%d",&c[l]);
            if(c[0]==1)
                for(l=1;l<j;l++)
                    if(c[l]-c[l-1]==1) ans-=2;
                    else break;
        }
        printf("%d\n",ans);
    }
}
