#include <cstdio>
#include <cstring>
using namespace std;
int dgt[10],dp[10][10];
int solve(int n){
	int i,j,ans=0;
	for(i=1;n;i++){
		dgt[i]=n%10;
		n/=10;
	}
	dgt[i]=0;
	for(i--;i>0;i--){
		for(j=0;j<dgt[i];j++)
			if(j!=4&&(j!=2||dgt[i+1]!=6))
				ans+=dp[i][j];
		if(dgt[i]==4||dgt[i]==2&&dgt[i+1]==6)
			break;
	}
	return ans;
}
int main(){
	int n,m,i,j,k;
	while(scanf("%d%d",&n,&m)&&n+m){
		memset(dp,0,sizeof(dp));
		for(dp[0][0]=i=1;i<8;i++)
			for(j=0;j<10;j++)
				for(k=0;k<10;k++)
					if(j!=4&&(j!=6||k!=2))
						dp[i][j]+=dp[i-1][k];
		printf("%d\n",solve(m+1)-solve(n));
	}
}