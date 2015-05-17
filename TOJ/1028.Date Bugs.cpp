#include <stdio.h>
int main()
{
    int n,y[20][10000],a,b,c,d,m,i,j,k=0;
    while(scanf("%d",&n)&&n)
    {
        for(i=0,c=0;i<n;i++)
        {
            scanf("%d%d%d",&y[i][0],&a,&b);
            b-a>c?(c=b-a,d=i):c;
            for(j=1;y[i][j-1]<10000;j++)
                y[i][j]=y[i][j-1]+b-a;
        }
        printf("Case #%d:\n",++k);
        for(c=0,m=0;m<n&&y[d][c]<10000;c++)
            for(i=0,m=0;i<n;i++)
            {
                for(j=0;m==i&&y[i][j]<10000;j++)
                    m+=y[i][j]-y[d][c]?0:1;
                if(m<=i)
                    break;
            }
        printf(n-m?"Unknown bugs detected.\n\n":"The actual year is %d.\n\n",y[d][c-1]);
    }
}
