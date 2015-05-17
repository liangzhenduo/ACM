#include <stdio.h>
#include <string.h>
#include <algorithm>
struct People{
    char name[21];
    int weight;
}peo[11];
bool cmp(const People &p,const People &q)
{
    return p.weight>q.weight;
}
int main()
{
    char str[5];
    int d,w,j=0,i;
    while(scanf("%s",str)!=EOF)
    {
        if(j)
            printf("\n");
        i=0;
        while(scanf("%s",peo[i].name)&&strcmp(peo[i].name,"END"))
        {
            scanf("%d%d",&d,&w);
            peo[i++].weight=w-d;
        }
        std::sort(peo,peo+i,cmp);
        for(j=0;j<i;j++)
            printf("%s\n",peo[j].name);
    }
}
