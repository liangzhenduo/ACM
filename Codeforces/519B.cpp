#include <stdio.h>
#include <algorithm>
int main(){
    int n,a[100001],b[100000],c[99999],i,j,k;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        std::sort(a,a+n);
        for(i=0;i<n-1;i++)
            scanf("%d",&b[i]);
        std::sort(b,b+n-1);
        for(i=0;i<n-2;i++)
            scanf("%d",&c[i]);
        std::sort(c,c+n-2);
        for(i=0;i<n;i++)
            if(a[i]-b[i]||i==n-1){
                printf("%d\n",a[i]);
                break;
            }
        for(i=0;i<n;i++)
            if(b[i]-c[i]||i==n-2){
                printf("%d\n",b[i]);
                break;
            }
    }
}
