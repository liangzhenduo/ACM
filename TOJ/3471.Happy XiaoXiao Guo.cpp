#include <stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
        puts(n%6%3?"Happy":"Unhappy");
}
