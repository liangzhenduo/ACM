#include <stdio.h>
#include <string.h>
#include <algorithm>
struct Ins{
    int index;
    int days;
}ins[101];
bool cmp(const Ins &p,const Ins &q){
    return p.days<q.days;
}
int main(){
    int n,k,i,j,num[101];
    while(scanf("%d%d",&n,&k)!=EOF){
        for(i=0;i<n;i++){
            scanf("%d",&ins[i].days);
            ins[i].index=i+1;
        }
        std::sort(ins,ins+n,cmp);
        memset(num,0,sizeof(num));
        for(j=i=0;i<n;i++)
            if(ins[i].days<=k){
                k-=ins[i].days;
                num[++j]=ins[i].index;
            }
        printf("%d\n",j);
        if(j){
            for(i=1;i<j;i++)
                printf("%d ",num[i]);
            printf("%d\n",num[j]);
        }
    }
}
