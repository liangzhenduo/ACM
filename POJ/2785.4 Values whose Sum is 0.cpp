#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int s[16000000],t[16000000];
int bs(int x,int l,int r){
    int mid=l+(r-l)/2;
    if(l>r) return -1;
    if(t[mid]==x) return mid;
    else if(t[mid]>x) return bs(x,l,mid-1);
    else return bs(x,mid+1,r);
}
int main(){
    int n,num[4000][4],i,j,k,m,ans,tmp;
    while(scanf("%d",&n)!=EOF){
        for(m=n*n,i=0;i<n;i++)
            for(j=0;j<4;j++)
                scanf("%d",&num[i][j]);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                s[n*i+j]=-num[i][0]-num[j][1],
                t[n*i+j]=num[i][2]+num[j][3];
        sort(s,s+m);
        sort(t,t+m);
        for(ans=i=0;i<m;i++){
            k=bs(s[i],0,m-1);
            if(k>=0)
                for(tmp=ans++,j=1;ans-tmp;j++){
                    tmp=ans;
                    if(k-j>=0&&t[k-j]==s[i]) ans++;
                    if(k+j<m&&t[k+j]==s[i]) ans++;
                }
        }
        printf("%d\n",ans);
    }
}
