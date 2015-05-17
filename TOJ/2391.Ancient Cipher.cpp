#include <stdio.h>
#include <string.h>
#include <algorithm>
int main()
{
    char s1[101],s2[101];
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        int t1[26]={0},t2[26]={0},k=1;
        for(int i=0;i<strlen(s1);i++)
            t1[s1[i]-65]++,t2[s2[i]-65]++;
        std::sort(t1,t1+26);
        std::sort(t2,t2+26);
        for(int j=25;j>=0;j--)
            if(t1[j]!=t2[j])
            {
                k--;
                break;
            }
        printf("%s\n",k?"YES":"NO");
    }
}
