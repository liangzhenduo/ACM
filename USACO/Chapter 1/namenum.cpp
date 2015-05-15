/*
ID: liangzh7
LANG: C++
TASK: namenum
*/
#include <cstdio>
#include <cstring>
const char code[26] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','0','7','7','8','8','8','9','9','9','0'};
char a[13],b[13],c[13];

int main(){
	freopen("namenum.in","r",stdin);
	freopen("namenum.out","w",stdout);
	freopen("dict.txt","r",stderr);
	int i;
	while(scanf("%s",a)!=EOF){
        int k=0,i;
        while(fscanf(stderr,"%s",b)!=EOF){
            if(code[b[0]-'A']!=a[0]) continue;
            for(i=0;b[i];++i)
                c[i]=code[b[i]-'A'];
            c[i]='\0';
            if(!strcmp(a,c)){
                k++;
                puts(b);
            }
        }
        if(!k) puts("NONE");
	}
}
