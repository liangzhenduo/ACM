/*
ID: liangzh7
LANG: C++
TASK: milk
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
struct Milk{
    int p,a;
}milk[5000];
bool cmp(Milk p,Milk q){
    return p.p<q.p;
}
int main(){
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	int n,m,i,j,k;
	while(scanf("%d%d",&n,&m)!=EOF){
        for(i=0;i<m;i++)
            scanf("%d%d",&milk[i].p,&milk[i].a);
        std::sort(milk,milk+m,cmp);
        for(k=j=i=0;i<m;i++){
            j+=milk[i].a;
            k+=milk[i].a*milk[i].p;
            if(j>=n){
                k-=(j-n)*milk[i].p;
                break;
            }
        }
        printf("%d\n",k);
	}
}
