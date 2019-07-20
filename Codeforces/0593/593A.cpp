#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int n,i,j,k,ans;
	int ab[26],a,b;
	int grid[26][26];
	char str[1005];
	while(scanf("%d",&n)!=EOF){
		memset(grid,0,sizeof(grid));
		for(i=0;i<n;i++){
			memset(ab,0,sizeof(ab));
			scanf("%s",str);
			for(j=0;j<strlen(str);j++)
				ab[str[j]-'a']=1;
			for(a=b=-1,k=j=0;j<26;j++){
				if(k==0&&ab[j])
					k++,a=j;
				else if(k==1&&ab[j])
					k++,b=j;
				else if(ab[j])
					k++;
			}
			if(k>2) continue;
			else if(k==2){
				grid[a][b]+=strlen(str);
				grid[b][a]+=strlen(str);
			}
			else if(k==1){
				for(j=0;j<26;j++)
					grid[a][j]+=strlen(str);
				for(j=0;j<26;j++)
					grid[j][a]+=strlen(str);
				grid[a][a]-=strlen(str);
			}
		}
		for(ans=0,i=0;i<26;i++)
			for(j=0;j<26;j++)
				if(grid[i][j]>ans)
					ans=grid[i][j];
		printf("%d\n",ans);
	}
}