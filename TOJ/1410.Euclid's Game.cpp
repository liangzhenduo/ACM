#include <stdio.h>
#include <algorithm>
int main()
{
    int n,m,k;
    while(scanf("%d%d",&n,&m)&&n+m)
    {
        for(k=0;;n%=m,k++)
        {
            if(n<m)
                std::swap(n,m);
            if(n==0||m==0||(n/m>=2)||(n%m==0))
                break;
        }
        puts(k%2?"Ollie wins":"Stan wins");
    }
}
