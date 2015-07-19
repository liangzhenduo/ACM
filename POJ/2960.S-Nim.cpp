#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int s[102],sg[10002],mk[10002];
char ans[102];
void getsg(int n){
    int i,j;
    sg[0]=0;
    memset(mk,-1,sizeof(mk));
    for(i=1;i<10001;i++){
        for(j=0;j<n&&s[j]<=i;j++)
            mk[sg[i-s[j]]]=i;
        for(j=0;mk[j]==i;j++);
        sg[i]=j;
    }
}
int main(){
    int k,i,j,m,l,h,tmp;
    while(scanf("%d",&k)&&k){
        for(i=0;i<k;i++)
            scanf("%d",&s[i]);
        sort(s,s+k);
        getsg(k);
        scanf("%d",&m);
        memset(ans,0,sizeof(ans));
        for(j=0;j<m;j++){
            scanf("%d",&l);
            for(tmp=i=0;i<l;i++){
                scanf("%d",&h);
                tmp^=sg[h];
            }
            if(tmp==0) ans[j]='L';
            else ans[j]='W';
        }
        ans[m]='\0';
        printf("%s\n",ans);
    }
    return 0;
}