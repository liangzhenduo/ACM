#include <cstdio>
#include <cstring>
using namespace std;
char str[200005];
int main(){
	int n,m,i,j;
	char a[2],b[2],alphabeta[26];
	while(scanf("%d%d",&n,&m)!=EOF){
		scanf("%s",str);
		for(i=0;i<26;i++)
			alphabeta[i]=i+'a';
		while(m--){
			scanf("%s%s",a,b);
			for(i=0;i<26;i++)
				if(alphabeta[i]==a[0])
					alphabeta[i]=b[0];
				else if(alphabeta[i]==b[0])
					alphabeta[i]=a[0];
		}
		for(j=0;j<n;j++)
			str[j]=alphabeta[str[j]-'a'];
		puts(str);
	}
}