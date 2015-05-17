#include <stdio.h>
#include <algorithm>
int n,t=0,i,j,k,m;
struct Number{int val,dig[10];}num[1001];
bool cmp(const Number &p,const Number &q)
{return p.dig[i]-q.dig[i]?p.dig[i]<q.dig[i]:p.val<q.val;}
int main()
{
    while(scanf("%d",&n)&&n)
    {
        for(i=m=0;i<n;i++)
        {
            scanf("%d",&num[i].val);
            for(j=0,k=num[i].val;j<10;j++,k/=10)
                num[i].dig[j]=k%10;
            for(j=9;j>=0;j--)
                if(num[i].dig[j])
                    break;
            m=j+1>m?j+1:m;
        }
        printf("Case %d:\n",++t);
        for(i=0;i<m;i++)
        {
            std::sort(num,num+n,cmp);
            for(j=0;j<n-1;j++)
                printf("%d ",num[j]);
            printf("%d\n",num[j]);
        }
    }
}
