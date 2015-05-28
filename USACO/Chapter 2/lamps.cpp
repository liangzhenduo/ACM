
/*
ID: liangzh7
LANG: C++
TASK: lamps
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
using namespace std;
struct Num{
    string v;
}num;
set<string> val;
vector<Num> ans;
int n,c,o,i,j,k,lgt[101];
bool cmp(Num p,Num q){
    return p.v<q.v;
}
void dfs(int id,bool cur[],int cnt){
    int i,j,k;
    bool tmp[101];
    string str="";
    if(cnt==c){
        for(j=i=0;i<n;i++)
            if(lgt[i]>=0&&lgt[i]-cur[i]){
                j=1;
                break;
            }
        if(!j){
            for(i=0;i<n;i++)
                str.append(cur[i]?"1":"0");
            if(val.find(str)==val.end()){
                val.insert(str);
                num.v=str;
                ans.push_back(num);
            }
        }
        return;
    }
    if(id==1)
        for(i=0;i<n;i++) cur[i]=!cur[i];
    else if(id==2)
        for(i=0;i<n;i+=2) cur[i]=!cur[i];
    else if(id==3)
        for(i=1;i<n;i+=2) cur[i]=!cur[i];
    else if(id==4)
        for(i=0;i<n;i+=3) cur[i]=!cur[i];
    for(i=0;i<n;i++) tmp[i]=cur[i];
    for(i=1;i<5;i++)
        dfs(i,tmp,cnt+1);
}
int main(){
    freopen("lamps.in","r",stdin);
    freopen("lamps.out","w",stdout);
    bool cur[101],tmp[101];
	while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++) lgt[i]=-1,cur[i]=1;
        scanf("%d",&c);
        c=(c-1)%4+1;
        val.clear();
        ans.clear();
        while(scanf("%d",&o)&&o+1)
            lgt[o-1]=1;
        while(scanf("%d",&o)&&o+1)
            lgt[o-1]=0;
        for(i=1;i<5;i++){
            for(j=0;j<n;j++)
                tmp[j]=cur[j];
            dfs(i,tmp,0);
        }
        if(val.empty()){
            puts("IMPOSSIBLE");
            continue;
        }
        sort(ans.begin(),ans.end(),cmp);
        for(i=0;i<ans.size();i++)
            cout<<ans[i].v<<endl;
	}
}
