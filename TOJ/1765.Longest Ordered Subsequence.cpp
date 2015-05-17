#include <cstdio>
#include <cstring>
int main(){
    int n,a[1000],i,j,k,b[1000];
    while(scanf("%d",&n)!=EOF){
        memset(b,0,sizeof(b));
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(b[0]=i=1;i<n;i++){
            for(k=0,j=i-1;j>=0;j--)
                if(a[i]>a[j]&&b[j]>k) k=b[j];
            b[i]=k+1;
        }
        for(k=i=0;i<n;i++)
            if(b[i]>k) k=b[i];
        printf("%d\n",k);
    }
}
