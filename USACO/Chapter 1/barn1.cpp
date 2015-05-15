/*
ID: liangzh7
LANG: C++
TASK: barn1
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(int p,int q){
    return p>q;
}
int main(){
	freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);
	int m,s,c,i,j,k,barn[200],dist[200];
	while(scanf("%d%d%d",&m,&s,&c)!=EOF){
        for(i=0;i<c;i++)
            scanf("%d",&barn[i]);
        sort(barn,barn+c);
        for(i=1;i<c;i++)
            dist[i]=barn[i]-barn[i-1]-1;
        sort(dist+1,dist+c,cmp);
        for(j=barn[c-1]-barn[0]+1,i=1;i<min(m,c);i++)
            j-=dist[i];
        printf("%d\n",j);
	}
}
