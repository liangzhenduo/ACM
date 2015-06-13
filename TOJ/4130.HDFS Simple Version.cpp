#include <cstdio>
#include <cstring>
int a[5000001];
int main(){
    int t,n,m,i,j;
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        m=2*n-2;
        while(m--){
            scanf("%d",&i);
            a[i]++;
        }
        for(j=0,i=1;j<2;i++)
            if(!a[i]){
                printf("%d %d\n",i,i);
                break;
            }
            else if(!j&&a[i]==1){
                j++;
                printf("%d ",i);
            }
            else if(j&&a[i]==1){
                j++;
                printf("%d\n",i);
            }
    }
}
