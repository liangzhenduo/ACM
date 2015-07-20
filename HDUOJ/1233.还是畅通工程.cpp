#include <cstdio>
#include <cstring>
int ma[101][101],rec[101],n,i,j;
int prim(){
    int sum,mini,k;
    for(sum=0,j=1;j<n;j++){
        mini=0xfffffff;
        for(i=2;i<=n;i++)
            if(!rec[i]&&mini>ma[1][i])
                mini=ma[1][i],k=i;
        sum+=mini,rec[k]=1;
        for(i=2;i<=n;i++)
            if(!rec[i]&&ma[k][i]<ma[1][i])
                ma[1][i]=ma[k][i];
    }
    return sum;
}
int main(){
    int x,y,l,m;
    while(scanf("%d",&n)&&n){
        m=n*(n-1)/2;
        memset(ma,0,sizeof(ma));
        for(i=0;i<m;i++){
            scanf("%d%d%d",&x,&y,&l);
            ma[x][y]=ma[y][x]=l;
        }
        memset(rec,0,sizeof(rec));
        printf("%d\n",prim());
    }
}
