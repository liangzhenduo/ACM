#include <cstdio>
int main(){
    int t,n,i,j,k,l,f[30000];
    bool flag;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&f[i]);
        for(l=k=i=1;k&&i<n;i++)
            if(f[i]<f[i-1]){
                k=0;
                for(flag=0,j=i;j<n;j++)
                    if(!flag&&f[j]<f[j-1]||flag&&f[j]>f[j-1]) l++,flag=!flag;
            }
        printf("%d\n",l);
    }
}
