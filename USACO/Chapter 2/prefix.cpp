/*
ID: liangzh7
LANG: C++
TASK: prefix
*/
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    freopen("prefix.in","r",stdin);
    freopen("prefix.out","w",stdout);
    char s[201][11],t[200001],tmp[77];
    int i,j,l,dp[201],k=0,flag=0,ans=0;
	while(scanf("%s",s[k])&&s[k][0]!='.') dp[k]=strlen(s[k]),k++;
	while(scanf("%s",tmp)!=EOF) strcat(t,tmp);
	for(i=0;i<strlen(t);i++){
		for(j=0;j<k;j++)
			if(i+dp[j]>strlen(t)) continue;
			else{
				flag=0;;
				for(l=0;l<dp[j];l++)
					if(t[i+l]!=s[j][l]){
					    flag=1;
                        break;
                    }
				if(!flag)
                    ans=(dp[j]+i>ans?dp[j]+i:ans);
			}
		if(i>=ans) break;
	}
	printf("%d\n",ans);
}
