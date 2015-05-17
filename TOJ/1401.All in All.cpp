#include <stdio.h>
#include <cstring>
using namespace std;
int main()
{
    char s[90001],t[90001];
    while(scanf("%s %s",s,t)!=EOF)
    {
        int i,j,k=0,p=0,q=0;
        for(i=0;i<strlen(s);i++)
        {
            for(j=q;j<strlen(t);j++)
                if(s[i]==t[j])
                {
                    q=j+1;
                    p++;
                    break;
                }
            if(p==strlen(s))
            {
                k++;
                break;
            }
        }
        if(k)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

