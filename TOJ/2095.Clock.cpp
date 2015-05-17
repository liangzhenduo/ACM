#include <stdio.h>
int main()
{
    puts("Initial time  Final time  Passes");
    int h1,h2,m1,m2,i,j,k,
    meet[11]={0,5,10,16,21,27,32,38,43,49,54};
    while(scanf("%d%d%d%d",&h1,&m1,&h2,&m2)!=EOF)
    {
        printf(h1>9?"       %d":"       0%d",h1);
        printf(m1>9?":%d":":0%d",m1);
        printf(h2>9?"       %d":"       0%d",h2);
        printf(m2>9?":%d":":0%d",m2);
        h2+=(h2<h1||h2==h1&&m2<m1)?12:0;
        for(i=h1,j=m1,k=0;i<h2||i==h2&&j<=m2;j++)
        {
            j-60?0:(j=0,i++);
            k+=(j==meet[i%12]&&i%12-11)?1:0;
        }
        printf("%8d\n",k);
    }
}
