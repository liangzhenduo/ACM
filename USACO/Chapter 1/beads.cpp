/*
ID: liangzh7
LANG: C++
TASK: beads
*/
#include <cstdio>
#include <cstring>
int main(){
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    int n,i,j,k,l,ans;
    char s[360],c;
	while(scanf("%d",&n)!=EOF){
        scanf("%s",s);
        for(ans=i=0;i<n;i++){
            c=s[i];
            if(c=='w')
                for(j=i+1;;j++){
                    if(j==n) j=0;
                    if(s[j]!='w'){
                        c=s[j];
                        break;
                    }
                    if(j==i){
                        ans=n;
                        break;
                    }
                }
            for(l=k=0,j=i;;j++){
                if(j==n) j=0;
                if(!k){
                    l++;
                    if(s[j]!=c&&s[j]!='w') k=1;
                }
                else{
                    if(s[j]==c) break;
                    l++;
                }
                if(l==n) break;
            }
            if(l>ans) ans=l;
        }
        printf("%d\n",ans);
	}
}
