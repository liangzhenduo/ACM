#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int n,a[101],nut,pre,i,j;
	while(scanf("%d",&n)!=EOF){
		nut=0;
		long long ans=1LL;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i]==1){
				if(nut>0)
					ans*=(i-pre);
				nut++;
				pre=i;
			}
		}
		cout<<(nut==0?nut:ans)<<endl;
	}
}