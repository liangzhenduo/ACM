/*
ID: liangzh7
LANG: C++
TASK: crypt1
*/
#include <cstdio>
#include <cstring>
bool num[10];
bool judge(int m){
    while(m){
        if(!num[m%10]) return false;
        m/=10;
    }
    return true;
}
int main(){
    freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);
    int n,i,j,k,ans;
    while(scanf("%d",&n)!=EOF){
        memset(num,0,sizeof(num));
        while(n--){
            scanf("%d",&k);
            num[k]=1;
        }
        for(ans=0,i=100;i<1000;i++){
            if(!judge(i)) continue;
            for(j=10;j<100&&i*j<10000;j++){
                if(i*(j/10)>999||i*(j%10)>999||!judge(j)||!judge(i*j)) continue;
                if(judge(i*(j%10))&&judge(i*(j/10)))
                    ans++;
            }
        }
        printf("%d\n",ans);
    }
}
