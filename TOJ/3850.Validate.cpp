#include <stdio.h>
#include <string.h>
int main()
{
    char str[81];
    int i,k,a,b;
    while(scanf("%s",str)!=EOF)
    {
        int l=strlen(str);
        if(str[0]<58&&str[0]>47&&(l==15||l==18))
        {
            for(k=1,i=1;k&&i<l-1;i++)
                str[i]<58&&str[i]>47?:k--;
            if(k&&(str[i]<58&&str[i]>47||str[i]==88))
            {
                puts("This is the cardID.");
                continue;
            }
        }
        else if(l>4&&l<17&&(str[0]>64&&str[0]<91||str[0]>96&&str[0]<123))
        {
            for(k=1,i=1;k&&i<l;i++)
                str[i]>47&&str[i]<58||str[i]>64&&str[i]<91||str[i]>96&&str[i]<123?:k--;
            if(k)
            {
                puts("This is a username.");
                continue;
            }
        }
        a=0,b=0,k=0;
        for(i=1;i<l-1;i++)
        {
            a=str[i]-64?a:i;
            b=str[i]-46?b:i;
        }
        if(a&&b&&b-a>1)
            for(k=1,i=0;k&&i<l;i++)
                if(i-a&&i-b)
                    str[i]>47&&str[i]<58||str[i]>64&&str[i]<91||str[i]>96&&str[i]<123?:k--;
        if(k)
        {
            puts("This is an Email.");
            continue;
        }
        puts("This is the wrong input.");
    }
}
