#include <cstdio>
#include <cstring>
int pipe[11][4]={{1,0,0,1},
                {1,1,0,0},
                {0,0,1,1},
                {0,1,1,0},
                {1,0,1,0},
                {0,1,0,1},
                {1,1,0,1},
                {1,0,1,1},
                {0,1,1,1},
                {1,1,1,0},
                {1,1,1,1}};
int m,n,map[101][101],idx[101][101];
void dfs(int r,int c,int id){
    if(r<0||r>2*m||c<0||c>2*n) return;
    if(idx[r][c]||map[r][c]<2) return;
    idx[r][c]=id;
    for(int dr=-1;dr<=1;dr++)
        for(int dc=-1;dc<=1;dc++)
            if(dr||dc) dfs(r+dr,c+dc,id);
}
int main(){
    int k,i,j;
    char p[51][51];
    while(scanf("%d%d",&m,&n)&&m+n>0){
        memset(map,0,sizeof(map));
        memset(idx,0,sizeof(idx));
        for(i=0;i<m;i++){
            scanf("%s",&p[i]);
            for(j=0;j<n;j++){
                map[1+2*i][1+2*j]=2;
                map[2*i][1+2*j]+=pipe[p[i][j]-65][0];
                map[1+2*i][2+2*j]+=pipe[p[i][j]-65][1];
                map[2+2*i][1+2*j]+=pipe[p[i][j]-65][2];
                map[1+2*i][2*j]+=pipe[p[i][j]-65][3];
            }
        }
        for(k=i=0;i<=2*m;i++)
            for(j=0;j<=2*n;j++)
                if(!idx[i][j]&&map[i][j]==2) dfs(i,j,++k);
        printf("%d\n",k);
    }
}
