#include <cstdio>
#include <algorithm>
int main(){
    int n,k,i,j,m[50];
    while(scanf("%d%d",&n,&k)!=EOF){
        for(i=0;i<n;i++)
            scanf("%d",&m[i]);
        std::sort(m,m+n);
        j=m[n-k];
        for(k=0,i=n-1;i>=0;i--)
            if(m[i]>=j&&m[i]>0)
                k++;
        printf("%d\n",k);
    }
}
