#include <stdio.h>
int main()
{
    int n,x,y;
    while(scanf("%d",&n)!=EOF)
    {
        int k,i,j,blo[3][100]={0};
        while(n--)
        {
            scanf("%d%d",&x,&y);
            blo[y][x]=1;
        }
        for(i=0,k=1;k&&i<101;i++)
            if(blo[0][i])
            {
                for(j=0,k=0;!k&&j<3;j++,i--)
                    k=(blo[0][i-1]||blo[1][i]||blo[2][i+1]||blo[1][i+2]||blo[0][i+3])?0:1;
                i+=4;
            }
        printf("%d\n",k);
    }
}
