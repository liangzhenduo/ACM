/*
ID: liangzh7
LANG: C++
TASK: milk2
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
int main(){
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    int n,i,j,s[5000],e[5000];
	while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            scanf("%d%d",&s[i],&e[i]);
        std::sort(s,s+n);
        std::sort(e,e+n);
        int t[5000]={e[0]-s[0]};
        int f[5000]={0};
        for(i=0;i<n;i++){
            if(i>0&&e[i-1]>=s[i])
                s[i]=s[i-1];
            t[i]=e[i]-s[i];
        }
        for(i=0;i<n;i++){
            if(i>0&&s[i]>e[i-1])
                f[i]=s[i]-e[i-1];
        }
        std::sort(t,t+n);
        std::sort(f,f+n);
        printf("%d %d\n",t[n-1],f[n-1]);
	}
}
