/*
ID: liangzh7
LANG: C++
TASK: ariprog
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
bool num[125001];
int main(){
    freopen("ariprog.in","r",stdin);
    freopen("ariprog.out","w",stdout);
    int n,m,i,j,k,l,flag;
	while(scanf("%d",&n)!=EOF){
        memset(num,0,sizeof(num));
        scanf("%d",&m);
        vector<int> squ;
        for(i=0;i<=m;i++)
            for(j=i;j<=m;j++){
                k=i*i+j*j;
                if(!num[k]){
                    squ.push_back(k);
                    num[k]=1;
                }
            }
        sort(squ.begin(),squ.end());
        m=2*m*m+1;
        for(flag=0,j=1;j<=m/(n-1);j++)
            for(i=0;i<squ.size();i++){
                for(k=1;squ[i]+(n-1)*j<=m&&k<n;k++)
                    if(!num[squ[i]+k*j]) break;
                if(k==n){
                    flag++;
                    printf("%d %d\n",squ[i],j);
                }
            }
        if(!flag) puts("NONE");
	}
}
