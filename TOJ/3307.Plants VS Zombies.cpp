#include <stdio.h>
#include <algorithm>
struct Zombie{
    int a,r;
}zom[101];
int cmp(const Zombie &p,const Zombie &q)
{
    return p.a<q.a;
}
int main()
{
    int n,t,v,d,i,k;
    while(scanf("%d%d",&n,&t)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&v,&d);
            zom[i].r=i+1;
            zom[i].a=v-d;
        }
        std::sort(zom,zom+n,cmp);
        for(i=0,k=1;i<n&&k;i++)
            if(t*i+t>zom[i].a)
            {
                k--;
                printf("The zombies eat your brains!\n");
            }
        if(k)
        {
            for(i=0;i<n-1;i++)
                printf("%d ",zom[i].r);
            printf("%d\n",zom[n-1].r);
        }
    }
}
