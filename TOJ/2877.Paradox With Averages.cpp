#include <stdio.h>
int main()
{
    int t,nc,ne,iqc[200001],iqe;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&nc,&ne);
        double sc=0,se=0;
        int i,k=0;
        for(i=0;i<nc;i++)
        {
            scanf("%d",&iqc[i]);
            sc+=iqc[i];
        }
        for(i=0;i<ne;i++)
        {
            scanf("%d",&iqe);
            se+=iqe;
        }
        for(i=0;i<nc;i++)
            if(iqc[i]<sc/nc&&iqc[i]>se/ne)
                k++;
        printf("%d\n",k);
    }
}
