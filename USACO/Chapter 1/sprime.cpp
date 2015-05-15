/*
ID: liangzh7
LANG: C++
TASK: sprime
*/
#include <cstdio>
#include <cstring>
int n;
bool isPrime(int k){
    for(int j=2;j*j<=k;j++)
        if(k%j==0)
            return false;
    return true;
}
void dfs(int k,int l){
    if(l==n){
        if(isPrime(k))
            printf("%d\n",k);
        return;
    }
    if(isPrime(k))
        for(int i=0;i<10;i++)
            dfs(10*k+i,l+1);
}
int main(){
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);
    while(scanf("%d",&n)!=EOF){
        for(int i=2;i<8;i++)
            dfs(i,1);
    }
}
