/*
ID: liangzh7
LANG: C++
TASK: dualpal
*/
#include <cstdio>
#include <cstring>
char o[20];
int n,s,i,j,k,l;
void base(int n,int b){
    int j;
    for(j=0;n;j++){
        o[j]=n%b+48;
        n/=b;
    }
    o[j]='\0';
}
bool pali(){
    for(int j=0;j<=strlen(o)/2;j++)
        if(o[j]!=o[strlen(o)-1-j]) return false;
    return true;
}
int main(){
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	while(scanf("%d%d",&n,&s)!=EOF){
        for(l=0,j=s+1;l<n;j++){
            for(k=0,i=2;k<2&&i<11;i++){
                base(j,i);
                if(pali()) k++;
            }
            if(k==2){
                printf("%d\n",j);
                l++;
            }
        }
	}
}
