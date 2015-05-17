#include <cstdio>
int main(){
    int t,n,i,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(m=0,i=1;m<n;i++)
            m+=i;
        printf("%d\n",i-1);
    }
}
