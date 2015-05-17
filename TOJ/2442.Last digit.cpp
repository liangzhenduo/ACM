#include <stdio.h>
#include <string.h>
int get(int n,int x)
{
    int k=0;
    while(n)
        k+=n/=x;
    return k;
}
int g(int n,int x)
{
    return n?n/10+(n%10>=x)+g(n/5,x):0;
}
int f(int n,int x)
{
    return n?f(n/2,x)+g(n,x):0;
}
int main()
{
    int n,m;
    int v2[4]={6,2,4,8};
    int v3[4]={1,3,9,7};
    int v7[4]={1,7,9,3};
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int k,
        c9=f(n,9)-f(n-m,9)-f(m,9),
        c7=f(n,7)-f(n-m,7)-f(m,7),
        c3=f(n,3)-f(n-m,3)-f(m,3)+2*c9,
        c2=get(n,2)-get(n-m,2)-get(m,2),
        c5=get(n,5)-get(n-m,5)-get(m,5);
        k=c5>c2?5:v3[c3%4]*v7[c7%4];
        if(c2>c5)
            k*=v2[(c2-c5)%4];
        printf("%d\n",k%10);
    }
}
