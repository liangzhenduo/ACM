#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int num[100001];
int main(){
	int n,i,j;
	long long sum;
	while(scanf("%d",&n)!=EOF){
		for(sum=i=0;i<n;i++){
			scanf("%d",&num[i]);
			sum+=num[i];
		}
		if(sum%2){
			sort(num,num+n);
			for(i=0;i<n;i++)
				if(num[i]%2){
					sum-=num[i];
					break;
				}
		}
		cout<<sum<<endl;
	}
}