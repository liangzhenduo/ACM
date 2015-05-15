/*
ID: liangzh7
LANG: C++
TASK: wormhole
*/
#include <cstdio>
struct Hole{
    long long x,y;
}hole[13];
long long p[13],r[13];

bool check(int n){
    int i,j,tmp;
    for(i=1;i<=n;i++){
        for(tmp=i,j=1;j<=n;j++)
            tmp=r[p[tmp]];
        if(tmp) return true;
    }
    return false;
}

int dfs(int n){
    int i,j,sum;
    for(i=1;p[i]&&i<=n;i++);
    if(i>n){
        if(check(n)) return 1;
        else return 0;
    }
    for(sum=0,j=i+1;j<=n;j++)
        if(!p[j]){
            p[i]=j;
            p[j]=i;
            sum+=dfs(n);
            p[i]=0;
            p[j]=0;
        }
    return sum;
}

int main(){
    freopen("wormhole.in","r",stdin);
    freopen("wormhole.out","w",stdout);
    int n,i,j;
	while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%lld%lld",&hole[i].x,&hole[i].y);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(hole[j].x>hole[i].x&&hole[j].y==hole[i].y&&(r[i]==0||hole[j].x-hole[i].x<hole[r[i]].x-hole[i].x))
                    r[i]=j;
        printf("%d\n",dfs(n));
	}
}
