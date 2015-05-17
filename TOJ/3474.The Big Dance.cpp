#include <cstdio>
int n,sum,num[2201];
void cow(int p,int q){
    if(q<=p) return;
    else if(q-p==1)
        sum+=p*q;
    else{
        cow(p,(q+p)/2);
        cow((q+p)/2+1,q);
    }
}
int main(){
    for(int i=0;i<2202;i++) num[i]=i;
    while(scanf("%d",&n)!=EOF){
        sum=0;
        cow(1,n);
        printf("%d\n",sum);
    }
}
