#include <stdio.h>
#include <string.h>
#include <algorithm>
int main()
{
    int digit[27][5];
    for(int j=0;j<5;j++)
        digit[0][j]=0;
    for(int i=1;i<27;i++)
    {
        digit[i][0]=i;
        for(int j=1;j<5;j++)
        {
            int q=1,p=1;
            for(int k=1;k<=j;k++)
            {
                q*=k;
                p*=(27-i-k);
            }
            digit[i][j]=p/q+digit[i-1][j];
        }
    }
    char word[6];
    while(scanf("%s",word)!=EOF)
    {
        std::reverse(word,word+strlen(word));
        int index=0;
        for(int i=0;i<strlen(word);i++)
        {
            if(i&&word[i]>=word[i-1])
            {
                index=0;
                break;
            }
            index+=digit[word[i]-96][i];
        }
        printf("%d\n",index);
    }
}
