/*
ID: liangzh7
LANG: C++
TASK: gift1
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
int main(){
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
	int n,m,i,j,k,gi[10],re[10];
	string name[10],na;
	while(cin>>n){
        map<string,int> id;
		for(i=0;i<n;i++){
			cin>>name[i];
			id[name[i]]=i;
			re[i]=0;
		}
		for(i=0;i<n;i++){
			cin>>na>>k>>m;
			if(m) k/=m;
			gi[id[na]]=(m*k);
			for(j=0;j<m;j++){
				cin>>na;
				re[id[na]]+=k;
			}
		}
        for(i=0;i<n;i++)
            cout<<name[i]<<" "<<re[i]-gi[i]<<endl;
	}
}
