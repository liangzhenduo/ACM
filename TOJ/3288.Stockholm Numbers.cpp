#include <stdio.h>
int main()
{
    int n,k;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&k);
        int j=2*k,c;
        for(c=0;j;c++)
            j&=(j-1);
        printf("%d\n",c%2?2*k+1:2*k);
    }
}
