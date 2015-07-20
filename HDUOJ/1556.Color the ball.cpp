#include <cstdio>
#include <cstring>
int n,c[110000];
int lowbit(int x){
    return x&(-x);
}
void modify(int x,int data){
    while(x>0){
        c[x]+=data;
        x-=lowbit(x);
    }
}
int get_sum(int x){
    int sum=0;
    while(x<=n){
        sum+=c[x];
        x+=lowbit(x);
    }
    return sum;
}
int main(){
    while(scanf("%d",&n)&&n){
        int a,b,i;
        memset(c,0,sizeof(c));
        for(i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            modify(b,1);
            modify(a-1,-1);
        }
        for(i=1;i<n;i++)
            printf("%d ",get_sum(i));
        printf("%d\n",get_sum(n));
    }
    return 0;
}
