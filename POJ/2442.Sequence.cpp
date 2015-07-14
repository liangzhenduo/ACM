#include <cstdio>
#include <algorithm>
using namespace std;
int fst[2001],nxt[2001],heap[2001];
int main(){
    int t,m,n,i,j,tmp,flag;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        for(m--,i=0;i<n;i++) scanf("%d",&fst[i]);
        sort(fst,fst+n);
        while(m--){
            for(i=0;i<n;i++) scanf("%d",&nxt[i]);
            sort(nxt,nxt+n);
            for(i=0;i<n;i++) heap[i]=fst[i]+nxt[0];
            make_heap(heap,heap+n);
            for(i=1;i<n;i++){
                flag=0;
                for(j=0;j<n;j++){
                    tmp=nxt[i]+fst[j];
                    if(tmp<heap[0]){
                        pop_heap(heap,heap+n);
                        heap[n-1]=tmp;
                        push_heap(heap,heap+n);
                        flag=1;
                    }
                    else break;
                }
                if(!flag) break;
            }
            for(i=0;i<n;i++) fst[i]=heap[i];
            sort(fst,fst+n);
        }
        for(i=0;i<n-1;i++)
            printf("%d ",fst[i]);
        printf("%d\n",fst[i]);
    }
}
