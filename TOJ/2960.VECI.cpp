#include <stdio.h>
#include <string.h>
#include <algorithm>
int main()
{
    char num[6];
    while(scanf("%s",num)!=EOF)
    {
        int i,j,k=1;
        for(i=strlen(num)-1;i>0&&k;i--)
        {
            for(j=i-1;j>=0;j--)
                if(num[j]<num[i])
                {
                    char tmp=num[i];
                    num[i]=num[j];
                    num[j]=tmp;
                    k--;
                    break;
                }
        }
        std::sort(num+j+1,num+strlen(num));
        printf("%s\n",k?"0":num);
    }
}
