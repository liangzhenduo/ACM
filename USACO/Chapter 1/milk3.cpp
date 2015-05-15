/*
ID: liangzh7
LANG: C++
TASK: milk3
*/
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
set<int> ans;
int A,B,C,i;
bool vis[21][21][21];
void dfs(int a,int b,int c){
    if(vis[a][b][c]) return;
    vis[a][b][c]=1;
    if(!a) ans.insert(c);
    if(A-a>0&&b){
        int k=min(A-a,b);
        dfs(a+k,b-k,c);
    }
    if(A-a>0&&c){
        int k=min(A-a,c);
        dfs(a+k,b,c-k);
    }
    if(B-b>0&&a){
        int k=min(B-b,a);
        dfs(a-k,b+k,c);
    }
    if(B-b>0&&c){
        int k=min(B-b,c);
        dfs(a,b+k,c-k);
    }
    if(C-c>0&&a){
        int k=min(C-c,a);
        dfs(a-k,b,c+k);
    }
    if(C-c>0&&b){
        int k=min(C-c,b);
        dfs(a,b-k,c+k);
    }
}
int main(){
    freopen("milk3.in","r",stdin);
    freopen("milk3.out","w",stdout);
	while(scanf("%d%d%d",&A,&B,&C)!=EOF){
        memset(vis,0,sizeof(vis));
        dfs(0,0,C);
        set<int>::iterator it;
        for(i=1,it=ans.begin();it!=ans.end();i++,it++){
            printf("%d",*it);
            printf(ans.size()-i?" ":"\n");
        }
        ans.clear();
	}
}
