/*
ID: liangzh7
LANG: C++
TASK: frac1
*/
#include <cstdio>
#include <algorithm>
using namespace std;
struct Fraction{
    int num,den;
}fra[25761];
bool cmp(Fraction p,Fraction q){
    if(p.num*q.den==p.den*q.num) return p.den<q.den;
    return p.num*q.den<p.den*q.num;
}
int main(){
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);
    int n,i,j,k;
	while(scanf("%d",&n)!=EOF){
        fra[0].num=0,fra[0].den=1;
        for(k=i=1;i<=n;i++)
            for(j=i;j<=n;j++,k++)
                fra[k].num=i,fra[k].den=j;
        sort(fra,fra+n*(n+1)/2,cmp);
        puts("0/1");
        for(i=1;i<=n*(n-1)/2;i++)
            if(fra[i].num*fra[i-1].den>fra[i].den*fra[i-1].num)
                printf("%d/%d\n",fra[i].num,fra[i].den);
        puts("1/1");
	}
}
