#include <cstdio>
#include <cstring>
int bal[100005],n;
int lowbit(int x){
	return x&(-x);
}
void update(int i,int val){
	while(i<=n){
		bal[i]+=val;
		i+=lowbit(i);
	}
}
int querry(int i){
    int sum=0;
	while(i>0){
        sum+=bal[i];
        i-=lowbit(i);
	}
	return sum;
}
int main(){
	int a,b,i;
	while(scanf("%d",&n)&&n){
		memset(bal,0,sizeof(bal));
		for(i=0;i<n;i++){
			scanf("%d%d",&a,&b);
			update(a,1);
			update(b+1,-1);
		}
		for(i=1;i<n;i++)
			printf("%d ",querry(i));
        printf("%d\n",querry(i));
	}
}
