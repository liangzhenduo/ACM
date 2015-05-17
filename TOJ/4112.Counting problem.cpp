#include <cstdio>
int main(){
    int t,n,c,sum,a[200001],i,j,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&c);
        for(k=0,i=1;i<=n;i++)
            for(sum=0,j=i;j<=n;j++){
                sum+=a[j];
                if(sum==c) {k++;break;}
                else if(sum>c) break;
            }
        printf("%d\n",k);
    }
}
