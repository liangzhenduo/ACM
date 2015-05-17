#include <stdio.h>
#include <algorithm>
int main()
{
    int n,k,p,q,m,num,pos[101],neg[101],res[101],i,j,s,t;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        m=0;
        for(i=p=q=0;i<n;i++)
        {
            scanf("%d",&num);
            num>=0?pos[p++]=num:neg[q++]=num;
        }
        std::sort(pos,pos+p),std::sort(neg,neg+q);
        if(k%2)
        {
            k--;
            if(p)
                res[m++]=pos[--p];
            else
            {
                for(i=q-1;i>q-1-k;i--)
                    printf("%d ",neg[i]);
                printf("%d\n",neg[q-1-k]);
                continue;
            }
        }
        for(i=j=0;i<k/2;i++)
        {
            s=t=-0xfffffff;
            if(p==1&&q-j==1)
                res[m++]=pos[--p],res[m++]=neg[j++];
            else
            {
                if(p>1)
                    s=pos[p-1]*pos[p-2];
                if(q-j>1)
                    t=neg[j]*neg[j+1];
                if(s>t)
                    res[m++]=pos[--p],res[m++]=pos[--p];
                else
                    res[m++]=neg[j++],res[m++]=neg[j++];
            }
        }
        std::sort(res,res+m);
        for(i=m-1;i>0;i--)
            printf("%d ",res[i]);
        printf("%d\n",res[i]);
    }
}
