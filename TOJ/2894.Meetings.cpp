#include <cstdio>
#include <algorithm>
int s[100000],e[100000];
int main(){
    int t,n,i,j,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d%d",&s[i],&e[i]);
        std::sort(s,s+n);
        std::sort(e,e+n);
        for(k=j=i=0;i<n;i++)
            if(s[i]<e[j]) k++;
            else j++;
        printf("%d\n",k);
    }
}
