#include <cstdio>
int main(){
    int n,k,p1,p2,t=0;
    char s1[9],s2[9];
    while(scanf("%d",&n)!=EOF&&n){
        scanf("%d",&k);
        if(t) puts("");
        t++;
        int tot[101]={0},win[101]={0};
        while(k--){
            scanf("%d%s%d%s",&p1,s1,&p2,s2);
            if(s1[0]!=s2[0]){
                tot[p1]++,tot[p2]++;
                if(s1[0]=='r'&&s2[0]=='s'||s1[0]=='s'&&s2[0]=='p'||s1[0]=='p'&&s2[0]=='r') win[p1]++;
                else win[p2]++;
            }
        }
        for(int i=1;i<=n;i++)
            printf(!tot[i]?"-\n":"%.3lf\n",double(win[i])/tot[i]);
    }
}
