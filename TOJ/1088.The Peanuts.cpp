#include <stdio.h>
#include <algorithm>
struct Peanut{
    int num,x,y;
}pea[2500];
bool cmp(const Peanut &p,const Peanut &q)
{
    return p.num>q.num;
}
int main()
{
    int t,m,n,k,i,j,l,num,res,cx,cy;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&m,&n,&k);
        for(i=l=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                scanf("%d",&num);
                if(num)
                    pea[l].x=i+1,pea[l].y=j+1,pea[l++].num=num;
            }
        std::sort(pea,pea+l,cmp);
        for(i=res=cx=0,cy=pea[0].y;k>0&&i<l;i++)
        {
            k-=(abs(pea[i].x-cx)+abs(pea[i].y-cy));
            if(k>pea[i].x)
                k--,res+=pea[i].num,cx=pea[i].x,cy=pea[i].y;
        }
        printf("%d\n",res);
    }
}
