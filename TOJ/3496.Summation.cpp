#include <stdio.h>
using namespace std;

    int reversed(int m)
    {
        int i,j,o=m;
        for(i=1;;i++)
        {
            if(o/10==0)
                break;
            o=o/10;
        }
        int p=0;
        for(o=0;;i--)
        {
            p=m%10;
            for(j=1;j<i;j++)
                p=p*10;
            o=o+p;
            if(i==1)
                break;
            m=m/10;
        }
        return o;
    }

int main()
{
    int n,x,y;
    scanf("%d",&n);
    for(int k=0;k<n;k++)
    {
        scanf("%d%d",&x,&y);
        int sum=reversed(x)+reversed(y);
        printf("%d\n\n",sum);
    }
    return 0;
}


