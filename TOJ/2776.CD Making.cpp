#include <stdio.h>
int main()
{
    int t,n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        printf("%d\n",(n==13&&k>=13)?2:((k==14&&n%k==13)?n/k+2:(k==13?(n%12?n/12+1:n/12):(n%k?n/k+1:n/k))));
    }
}
