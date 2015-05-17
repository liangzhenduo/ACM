#include <stdio.h>
using namespace std;
int a[2537209]={0},result[500001];
int main()
{
    for(int i=0;i<500001;i++)
    {
        if(i==0)
            result[i]=0;
        else if(result[i-1]>i&&a[result[i-1]-i]==0)
        {
            result[i]=result[i-1]-i;
            a[result[i]]=1;
        }
        else
        {
            result[i]=result[i-1]+i;
            a[result[i]]=1;
        }
    }
    int k;
    while(scanf("%d",&k)&&k!=-1)
        printf("%d\n",result[k]);
    return 0;
}

