#include <stdio.h>
int main()
{
    int n,m,k,i,j,t=0,dis,x,y;
    char cit[201][201],dir[5];
    while(scanf("%d%d%d",&m,&n,&k)&&k)
    {
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                cit[i][j]='.';
        x=0,y=0;
        while(k--)
        {
            scanf("%s%d",dir,&dis);
            if(!(x+y))
                cit[0][0]=dir[0]-'S'?'-':'|';
            if(dir[0]=='S')
                while(dis--)
                    cit[++y][x]=cit[y][x]-'.'?'+':'|';
            else if(dir[0]=='E')
                while(dis--)
                    cit[y][++x]=cit[y][x]-'.'?'+':'-';
            else if(dir[0]=='N')
                while(dis--)
                    cit[--y][x]=cit[y][x]-'.'?'+':'|';
            else if(dir[0]=='W')
                while(dis--)
                    cit[y][--x]=cit[y][x]-'.'?'+':'-';
            cit[y][x]=k?'+':cit[y][x];
        }
        printf("Scenario #%d:\n",++t);
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                printf("%c",cit[i][j]);
            printf("\n");
        }
    }
}
