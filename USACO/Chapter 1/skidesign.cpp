/*
ID: liangzh7
LANG: C++
TASK: skidesign
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	freopen("skidesign.in","r",stdin);
    freopen("skidesign.out","w",stdout);
    int n,i,j,k,ans,h[1000];
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            scanf("%d",&h[i]);
        sort(h,h+n);
        for(ans=0xfffffff,i=0;i<84;i++){
            for(k=j=0;j<n;j++){
                if(h[j]<i) k+=(i-h[j])*(i-h[j]);
                if(h[j]>i+17) k+=(h[j]-i-17)*(h[j]-i-17);
            }
            ans=min(ans,k);
        }
        printf("%d\n",ans);
    }
}
