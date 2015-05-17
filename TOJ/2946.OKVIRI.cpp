#include <stdio.h>
#include <string.h>
int main()
{
    int i,j;
    char str[16],fra[5][62];
    scanf("%s",str);
    memset(fra,'.',sizeof(fra));
    for(i=2,j=0;i<=4*strlen(str);i+=4,j++)
        fra[0][i]=fra[4][i]=i%12-10?'#':'*',fra[2][i]=str[j];
    for(i=1;i<=4*strlen(str);i+=2)
        fra[1][i]=fra[3][i]=i%12-9&&i%12-11?'#':'*';
    for(i=0;i<=4*strlen(str);i+=4)
        fra[2][i]=i%12==8&&i<4*strlen(str)||i%12==0&&i?'*':'#';
    for(i=0;i<5;i++)
    {
        for(j=0;j<=4*strlen(str);j++)
            printf("%c",fra[i][j]);
        puts("");
    }
}
