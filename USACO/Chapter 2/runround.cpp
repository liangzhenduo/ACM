/*
ID: liangzh7
LANG: C++
TASK: runround
*/
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    freopen("runround.in","r",stdin);
    freopen("runround.out","w",stdout);
    unsigned long n,k,l;
    int i,j,m,num[10],cnt[10],vst[10],flag;
	while(scanf("%ld",&n)!=EOF){
        for(l=n+1;;l++){
            memset(cnt,0,sizeof(cnt));
            for(flag=0,k=l,i=0;k;i++,k/=10){
                num[i]=k%10;
                cnt[num[i]]++;
                if(cnt[num[i]]>1){
                    flag=1;
                    break;
                }
            }
            if(flag||cnt[i]||cnt[0]) continue;
            memset(vst,0,sizeof(vst));
            for(m=0,k=i-1,j=num[k]%i;m<i;m++,j=num[k]%i){
                if(k>=j) k-=j;
                else k=k+i-j;
                if(!vst[k]) vst[k]++;
                else break;
            }
            if(k==i-1){
                printf("%ld\n",l);
                break;
            }
        }
	}
}
