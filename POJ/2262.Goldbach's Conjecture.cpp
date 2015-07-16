#include <cstdio>
int num[1000000];
int main(){
    int n,i,j;
    for(i=2;i<1001;i++)
        if(num[i]==0)
            for(j=i*i;j<1000001;j+=i) num[j]=1;
    while(scanf("%d",&n)&&n){
        for(i=2;i<n;i++)
            if(num[i]==0&&num[n-i]==0) break;
        printf("%d = %d + %d\n",n,i,n-i);
    }
}
