#include <cstdio>
#include <algorithm>
int main(){
    int t,n,m,a,b,i,j,mon[16],mag[100],moda,mada;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&m,&a,&b);
        for(moda=i=0;i<n;i++)
            scanf("%d",&mon[i]),moda+=mon[i];
        for(mada=i=0;i<m;i++)
            scanf("%d",&mag[i]),mada+=mag[i];
        if(mada>=a) puts("wellplay");
        else if(n==1&&mada<a) puts("wash your face");
        else{
            std::sort(mon,mon+n);
            if(mon[n-1]>=b){
                for(i=0;i<n;i++)
                if(mon[i]>=b){
                    moda-=mon[i];
                    break;
                }
                if(mada+moda>=a) puts("wellplay");
                else puts("wash your face");
            }
            else{
                for(i=0;b>0&&i<n;i++)
                    b-=mon[i],moda-=mon[i];
                if(b>0){
                    std::sort(mag,mag+m);
                    for(i=0;b>0&&i<m;i++)
                        b-=mag[i],mada-=mag[i];
                }
                if(mada+moda>=a) puts("wellplay");
                else puts("wash your face");
            }
        }
    }
}
