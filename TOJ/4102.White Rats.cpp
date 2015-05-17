#include <cstdio>
int main(){
    int t,n,i,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(m=1,i=0;m<n;i++)
            m*=2;
        printf("%d\n",i);
    }
}
