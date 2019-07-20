#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    int n,i,j,k,p,x,y,s[1000],sum,t[1000],l;
    while(scanf("%d%d%d%d%d",&n,&k,&p,&x,&y)!=EOF){
        for(sum=i=0;i<k;i++){
            scanf("%d",&s[i]);
            sum+=s[i];
        }
        sort(s,s+k);
        for(j=i=0;i<k;i++)
            if(s[i]<y) j++;
            else break;
        for(l=i=0;i<n/2-k+j+1;i++)
                t[l++]=y;
            for(i=0;i<n/2-j;i++)
                t[l++]=1;
            for(i=0;i<n-k;i++){
                sum+=t[i];
                if(t[i]<y) j++;
            }
            if(j<=n/2&&sum<=x){
                for(i=0;i<n-k-1;i++) printf("%d ",t[i]);
                printf("%d\n",t[n-k-1]);
            }
            else puts("-1");

    }
}
