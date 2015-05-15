/*
ID: liangzh7
LANG: C++
TASK: palsquare
*/
#include <cstdio>
#include <cstring>
const char c[21]="0123456789ABCDEFGHIJ";
char o[10],p[20];
int b,i,j;
void base(int n,char a[]){
    for(j=0;n;j++){
        a[j]=c[n%b];
        n/=b;
    }
    a[j]='\0';
}
bool pali(){
    for(j=0;j<=strlen(p)/2;j++)
        if(p[j]!=p[strlen(p)-1-j]) return false;
    return true;
}
int main(){
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	while(scanf("%d",&b)!=EOF){
        for(i=1;i<301;i++){
            base(i*i,p);
            if(pali()){
                base(i,o);
                for(j=strlen(o)-1;j>=0;j--)
                    printf("%c",o[j]);
                printf(" %s\n",p);
            }
        }
	}
}
