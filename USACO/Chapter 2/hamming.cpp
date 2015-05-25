/*
ID: liangzh7
LANG: C++
TASK: hamming
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    freopen("hamming.in","r",stdin);
    freopen("hamming.out","w",stdout);
    int n,b,d,i,j,k,l,bin[64][8],cur[8],flag,h;
	while(scanf("%d%d%d",&n,&b,&d)!=EOF){
        memset(bin,0,sizeof(bin));
        for(k=0,i=1;k<n-1&&i<256;i++){
            memset(cur,0,sizeof(cur));
            for(l=i,j=0;l>0;j++,l/=2)
                if(l%2) cur[j]=1;
            for(flag=1,l=0;flag&&l<=k;l++){
                for(h=j=0;j<b;j++)
                    if(cur[j]-bin[l][j]) h++;
                if(h<d){
                    flag=0;
                    break;
                }
            }
            if(!flag) continue;
            for(k++,j=0;j<b;j++)
                bin[k][j]=cur[j];
        }
        for(i=0;i<n;i++){
            for(l=1,h=j=0;j<b;j++,l*=2)
                h+=l*bin[i][j];
            printf("%d",h);
            printf((i%10-9&&i<n-1)?" ":"\n");
        }
	}
}
