#include <cstdio>
#include <map>
using namespace std;
map<int,int,greater<int> > ma;			  
int gcd(int x,int y){
  	return y?gcd(y,x%y):x;
}
int main(){
	int n,m,i,j;
	int ans[501];
  	while(scanf("%d",&n)!=EOF){
  		m=n*n;
  		for(i=0;i<m;i++){
    		scanf("%d",&j); 
    		ma[j]++;
  		}
  		map<int,int,greater<int> >::iterator it;
	  	for(j=0,it=ma.begin();it!=ma.end();){
		    if(!(*it).second){
		    	it++;
		    	continue;
		    }
		    (*it).second--;
		    for(i=0;i<j;i++)
		       	ma[gcd((*it).first,ans[i])]-=2;
		    ans[j++]=(*it).first;
		}
		for(i=0;i<n-1;i++) printf("%d ",ans[i]);
		printf("%d\n",ans[i]);
  	}
}