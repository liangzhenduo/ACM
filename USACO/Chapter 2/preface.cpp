/*
ID: liangzh7
LANG: C++
TASK: preface
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    freopen("preface.in","r",stdin);
    freopen("preface.out","w",stdout);
    int n,i,j,k,rom[3501][7]={0},cur[7];
    char num[4][10][5]={{"","I","II","III","IV","V","VI","VII","VIII","IX"},
                        {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
                        {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
                        {"","M","MM","MMM"}},cha[8]="IVXLCDM",str[16];
    map<char,int> idx;
    for(i=0;i<7;i++) idx[cha[i]]=i;
    for(i=1;i<3501;i++){
        memset(cur,0,sizeof(cur));
        memset(str,0,sizeof(str));
        for(k=i,j=0;j<4;j++,k/=10)
            strcat(str,num[j][k%10]);
        for(j=0;j<strlen(str);j++)
            cur[idx[str[j]]]++;
        for(j=0;j<7;j++)
            rom[i][j]=rom[i-1][j]+cur[j];
    }
	while(scanf("%d",&n)!=EOF){
        for(i=0;i<7;i++)
            if(rom[n][i])
                printf("%c %d\n",cha[i],rom[n][i]);
	}
}
