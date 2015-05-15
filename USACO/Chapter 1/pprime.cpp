/*
ID: liangzh7
LANG: C++
TASK: pprime
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int num[800],bit[5],t=0;
bool isPrime(int k){
    for(int j=2;j*j<=k;j++)
        if(k%j==0)
            return false;
    return true;
}
void pal(int n){
    int tmp=n,i=0,j,sum=0;
    while(tmp){
        bit[i++]=tmp%10;
        tmp/=10;
    }
    for(j=1,--i;i>0;j*=10,i--)
        sum+=bit[i]*j;
    if(isPrime(sum+n*j)) num[t++]=sum+n*j;
    sum+=bit[0]*j;
    if(isPrime(sum+n*j*10)) num[t++]=sum+n*j*10;
}
int main(){
    freopen("pprime.in","r",stdin);
    freopen("pprime.out","w",stdout);
    int a,b,i;
    for(i=1;i<10000;i++)
        pal(i);
    sort(num,num+t);
    while(scanf("%d%d",&a,&b)!=EOF){
        for(i=0;num[i]<a;i++);
        for(i;num[i]<=b&&i<782;i++)
            printf("%d\n",num[i]);
    }
}
