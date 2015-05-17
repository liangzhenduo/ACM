#include <stdio.h>
#include <math.h>
int main()
{
    int c,n,k,i,j;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d",&n);
        for(i=1,k=268435455;i<=sqrt(n);i++)
            if(!(n%i))
                for(j=1;j<=sqrt(n/i);j++)
                    if((n/i)%j==0)
                        k=2*(i*j+n/i+n/j)<k?2*(i*j+n/i+n/j):k;
        printf("%d\n",k);
    }
}
