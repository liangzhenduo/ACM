#include <stdio.h>
int main()
{
    int n,k,i,j,m,res[3000]={0},que[40010]={1,1,0};
    for(k=0;k<3001;k++)
    {
        for(i=res[k-1]+1;que[i];i++);
        res[k]=i;
        for(j=i+1,m=i;j<40010;j++)
            que[j]||--m?:(que[j]=1,m=i);
    }
    while(scanf("%d",&n)&&n)
        printf("%d\n",res[n-1]);
}
