#include <cstdio>
long long x[2000],y[2000],k;
int main(){
    int n,i,j,a,b;
    while(scanf("%d",&n)!=EOF){
        for(k=20000000000,i=0;i<n;i++){
            scanf("%d%d",&x[i],&y[i]);
            for(j=0;j<i;j++)
                if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<k)
                    k=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]),a=j,b=i;
        }
        printf("%d %d\n",a+1,b+1);
    }
}
