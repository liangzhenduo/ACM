/*
ID: liangzh7
LANG: C++
TASK: holstein
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    freopen("holstein.in","r",stdin);
    freopen("holstein.out","w",stdout);
    int v,vit[25],g,gro[15][25],i,j,k,l,bin[15],q,p,ans[15],sum,flag;
	while(scanf("%d",&v)!=EOF){
        for(i=0;i<v;i++) scanf("%d",&vit[i]);
        scanf("%d",&g);
        for(k=1<<g,j=0;j<g;j++)
            for(i=0;i<v;i++)
                scanf("%d",&gro[j][i]);
        for(p=15,i=1;i<k;i++){
            memset(bin,0,sizeof(bin));
            for(l=i,q=j=0;l>0;j++,l/=2)
                if(l%2) q++,bin[j]=1;
            if(q>=p) continue;
            for(flag=1,j=0;j<v;j++){
                for(sum=l=0;l<g;l++)
                    if(bin[l]) sum+=gro[l][j];
                if(sum<vit[j]){
                    flag=0;
                    break;
                }
            }
            if(!flag) continue;
            for(p=q,j=0;j<g;j++)
                ans[j]=bin[j];
        }
        printf("%d",p);
        for(i=0;i<g;i++)
            if(ans[i])
                printf(" %d",i+1);
        puts("");
	}
}
