#include <cstdio>
#include <cstring>
int b[1000001];
int main(){
    int n,k,m,i;
    while(scanf("%d",&n)!=EOF){
        memset(b,0,sizeof(b));
        for(i=n;i>=n/2;i--) b[i]=1;
        for(m=0,i=n/2-1;i>0;i--)
            if(b[2*i+2])
                m++;
            else b[i]=1;
        printf("%d\n",n-m);
    }
}
