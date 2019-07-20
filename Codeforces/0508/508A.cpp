#include <stdio.h>
#include <string.h>
int map[1002][1002];
bool loss(int n,int m){
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            if(map[n+i][m+j]&&map[n+i+1][m+j]&&map[n+i][m+j+1]&&map[n+i+1][m+j+1])
                return true;
    return false;
}
int main(){
    int n,m,k,i,j,x,y;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        memset(map,0,sizeof(map));
        for(i=0,j=0;i<k;i++){
            scanf("%d%d",&x,&y);
            map[x][y]=1;
            if(!j&&loss(x-1,y-1))
                j=i+1;
        }
        printf("%d\n",j);
    }
}
