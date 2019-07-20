#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
pair<int,int> leg[100001];
int main(){
    int n,sum,i,j,k,l,r,m,len[201];
    while(scanf("%d",&n)!=EOF){
        memset(len,0,sizeof(len));
        memset(leg,0,sizeof(leg));
        for(i=0;i<n;i++) scanf("%d",&leg[i].first);
        for(sum=i=0;i<n;i++) scanf("%d",&leg[i].second),sum+=leg[i].second;
        sort(leg,leg+n);
        for(k=100000000,l=0;l<n;l=r+1){
            r=l;
            while(leg[r+1].first==leg[l].first&&r+1<n) r++;
            for(i=l;i<=r;i++) sum-=leg[i].second;
            m=2*l>r?2*l-r:0;
            for(j=sum,i=1;i<201;i++){
                if(m>=len[i]) j+=i*len[i],m-=len[i];
                else j+=m*i,m=0;
            }
            k=min(k,j);
            for(i=l;i<=r;i++) len[leg[i].second]++;
        }
        printf("%d\n",k);
    }
}
