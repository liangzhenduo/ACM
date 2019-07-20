#include <stdio.h>
int main(){
    char chess[8][9];
    while(scanf("%s",chess[0])!=EOF){
        for(int i=1;i<8;i++)
            scanf("%s",chess[i]);
        int w=0,b=0;
        for(int j=0;j<8;j++)
        for(int i=0;i<8;i++){
            if(chess[j][i]=='Q')
                w+=9;
            else if(chess[j][i]=='q')
                b+=9;
            else if(chess[j][i]=='R')
                w+=5;
            else if(chess[j][i]=='r')
                b+=5;
            else if(chess[j][i]=='B'||chess[j][i]=='N')
                w+=3;
            else if(chess[j][i]=='b'||chess[j][i]=='n')
                b+=3;
            else if(chess[j][i]=='P')
                w+=1;
            else if(chess[j][i]=='p')
                b+=1;
        }
        if(w==b) puts("Draw");
        else puts(w>b?"White":"Black");
    }
}
