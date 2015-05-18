#include <stdio.h>
int map[12][12]={0};
int main(){
    int i,j,k,l,n;
    for(i=1;i<11;i++)
        map[i][1]=map[1][i]=1;
    for(i=2;i<11;i++)
        for(j=2;j<11;j++){
            for(k=0,l=1;l<=j;l++)
                k+=map[i-1][l];
            map[i][j]=k;
        }
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",map[n][n]);
}
