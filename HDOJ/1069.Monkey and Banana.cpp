#include <cstdio>
#include <algorithm>
using namespace std;
struct Block{
    int x,y,z;
}blk[90];
bool cmp(Block p,Block q){
    if(p.x==q.x) return p.y<q.y;
    return p.x<q.x;
}
int main(){
    int cas=0,n,i,j,k,a,b,c,dp[90],h;
    while(scanf("%d",&n)&&n){
        for(i=0;i<3*n;){
            scanf("%d%d%d",&a,&b,&c);
            blk[i].x=max(a,b),blk[i].y=min(a,b),blk[i++].z=c;
            blk[i].x=max(a,c),blk[i].y=min(a,c),blk[i++].z=b;
            blk[i].x=max(c,b),blk[i].y=min(c,b),blk[i++].z=a;
        }
        sort(blk,blk+3*n,cmp);
        for(h=i=0;i<3*n;i++){
            dp[i]=blk[i].z;
            for(j=0;j<=i;j++){
                if(blk[i].x>blk[j].x&&blk[i].y>blk[j].y)
                    dp[i]=max(dp[i],dp[j]+blk[i].z);
                h=max(h,dp[i]);
            }
        }
        printf("Case %d: maximum height = %d\n",++cas,h);
    }
}
