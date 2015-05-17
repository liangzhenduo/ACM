#include <stdio.h>
#include <math.h>
int main()
{
    int rec[10036]={0};
    for(int i=1;i<10001;i++)
    {
        int k=i,j=i;
        while(k)
        {
            j+=k%10;
            k/=10;
        }
        rec[j]++;
    }
    for(int i=1;i<10001;i++)
        rec[i]?:printf("%d\n",i);
}
