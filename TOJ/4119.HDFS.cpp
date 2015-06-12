#include <cstdio>
#include <cstring>
int main(){
    int t,n,m,i,j,k;
    unsigned int a[156251],b[156251],d,p,q;
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d",&n);
        m=2*n-2;
        while(m--){
            scanf("%d",&d);
            d--,i=d/32,j=d%32;
            d=1<<j;
            p=a[i]&d;
            if(!p) a[i]+=d;
            else b[i]+=d;
        }
        for(k=i=0;k<2;i++)
            for(j=0;k<2&&j<32;j++){
                d=1<<j;
                p=a[i]&d,q=b[i]&d;
                if(!p){
                    printf("%d %d\n",32*i+j+1,32*i+j+1);
                    k=2;
                }
                else if(!k&&p>q){
                    printf("%d ",32*i+j+1);
                    k++;
                }
                else if(k&&p>q){
                    printf("%d\n",32*i+j+1);
                    k++;
                }
            }
    }
}
