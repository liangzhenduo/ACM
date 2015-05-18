#include <cstdio>
#include <cstring>
int main(){
    int n,s,i,j,k,num[4];
    while(scanf("%d",&n)!=EOF){
        memset(num,0,sizeof(num));
        for(i=0;i<n;i++){
            scanf("%d",&s);
            num[s-1]++;
        }
        k=num[3]+num[2];
        num[0]-=num[2];
        k+=num[1]/2;
        j=2*(num[1]%2)+(num[0]>0?num[0]:0);
        k+=(j%4?j/4+1:j/4);
        printf("%d\n",k);
    }
}
