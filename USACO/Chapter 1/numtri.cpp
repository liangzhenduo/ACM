/*
ID: liangzh7
LANG: C++
TASK: numtri
*/
#include <cstdio>
#include <algorithm>
int main(){
    freopen("numtri.in","r",stdin);
    freopen("numtri.out","w",stdout);
    int r,i,j,k,tri[1000][1000];
    while(scanf("%d",&r)!=EOF){
        for(i=0;i<r;i++)
            for(j=0;j<=i;j++)
                scanf("%d",&tri[i][j]);
        for(i=r-2;i>=0;i--)
            for(j=0;j<=i;j++)
                tri[i][j]+=std::max(tri[i+1][j],tri[i+1][j+1]);
        printf("%d\n",tri[0][0]);
    }
}
