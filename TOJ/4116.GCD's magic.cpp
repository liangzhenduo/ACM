#include <cstdio>
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    int n,t,a[100000],i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=n-1;i>0;i--)
            a[i-1]=gcd(a[i],a[i-1]);
        printf("%d\n",a[0]);
    }
}
