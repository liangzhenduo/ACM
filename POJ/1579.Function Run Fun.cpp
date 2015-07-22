#include <cstdio>
int w[21][21][21];
int main(){
    int a,b,c,i,j,k;
    for(i=0;i<21;i++)
        for(j=0;j<21;j++)
            for(k=0;k<21;k++)
                w[i][j][k]=1;
    for(i=1;i<21;i++)
        for(j=1;j<21;j++)
            for(k=1;k<21;k++)
                if(a<b&&b<c)
                    w[i][j][k]=w[i][j][k-1]+w[i][j-1][k-1]-w[i][j-1][k];
                else
                    w[i][j][k]=w[i-1][j][k]+w[i-1][j-1][k]+w[i-1][j][k-1]-w[i-1][j-1][k-1];
    while(scanf("%d%d%d",&a,&b,&c)&&!(a==-1&&b==-1&&c==-1)){
        printf("w(%d, %d, %d) = ",a,b,c);
        if(a<1||b<1||c<1)
            puts("1");
        else if(a>20||b>20||c>20)
            printf("%d\n",w[20][20][20]);
        else
            printf("%d\n",w[a][b][c]);
    }
}
