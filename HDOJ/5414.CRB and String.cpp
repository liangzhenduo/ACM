#include <cstdio>
#include <cstring>
int main(){
	char s[100005],t[100005];
	int c,i,j,k,l,p,q,flag;
	scanf("%d",&c);
	while(c--){
		scanf("%s%s",s,t);
		p=strlen(s),q=strlen(t);
		for(l=i=1;i<q;i++)
			if(t[i]==t[0]) l++;
			else break;
		for(flag=i=0;i<l;i++)
			if(s[i]!=t[0]){
				flag=1;
				break;
			}
		if(!flag)
			for(flag=k=i=j=0;j<q&&p<=q;j++,i++){
				if(s[i-k]==t[j]) continue;
				p++,k++;
			}
		puts(p>q||flag?"No":"Yes");
	}
}