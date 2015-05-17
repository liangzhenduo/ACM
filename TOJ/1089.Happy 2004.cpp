#include <stdio.h>
int main()
{
    int x,a,b,c,i;
    while(scanf("%d",&x)&&x)
    {
        for(i=0,a=b=c=1;i<=x%28;i++)
            a=a*(i-x%28?4:2)%29,b=b*3%29,c=c*22%29;
        printf("%d\n",(a-1)*(b-1)*(c-1)*9%29);
    }
}
