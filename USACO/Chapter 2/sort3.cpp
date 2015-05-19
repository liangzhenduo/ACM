/*
ID: liangzh7
LANG: C++
TASK: sort3
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w",stdout);
    int n,i,j,k,ori[1001],sor[1001],a[4][4],b,c,d,ans;
	while(scanf("%d",&n)!=EOF){
        memset(a,0,sizeof(a));
        for(i=0;i<n;i++){
            scanf("%d",&ori[i]);
            sor[i]=ori[i];
        }
        sort(sor,sor+n);
        for(i=0;i<n;i++)
            a[ori[i]][sor[i]]++;
        b=min(a[1][2],a[2][1]);
        c=min(a[1][3],a[3][1]);
        d=min(a[2][3],a[3][2]);
        ans=b+c+d;
        a[1][2]-=b,a[2][1]-=b;
        a[1][3]-=c,a[3][1]-=c;
        a[2][3]-=d,a[3][2]-=d;
        ans+=(a[1][2]+a[2][1]+a[1][3]+a[3][1]+a[2][3]+a[3][2])*2/3;
        printf("%d\n",ans);
	}
}
