#include <cstdio>
using namespace std;
int main(){
    int n,i,j,g[1001];
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++) scanf("%d",&g[i]);
        while(g[0])
            for(i=0;i<n;i++)
                if(i%2==0){
                    if(g[i]==n-1) g[i]=0;
                    else g[i]++;
                }
                else{
                    if(g[i]==0) g[i]=n-1;
                    else g[i]--;
                }
        for(j=1,i=0;i<n;i++)
            if(g[i]-i){
                j=0;
                break;
            }
        if(j) puts("Yes");
        else puts("No");
    }
}
