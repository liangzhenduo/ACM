#include <cstdio>
#include <cstring>
#define maxn 32005
int cor[maxn],cnt[maxn];
int lowbit(int x){
	return x&(-x);
}
void add(int i,int val){
	while(i<maxn){
		cor[i]+=val;
		i+=lowbit(i);
	}
}
int sum(int i){
    int sum=0;
	while(i>0){
        sum+=cor[i];
        i-=lowbit(i);
	}
	return sum;
}
int main(){
	int n,x,y,i;
	while(scanf("%d",&n)!=EOF){
		memset(cor,0,sizeof(cor));
		memset(cnt,0,sizeof(cnt));
		for(i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			cnt[sum(++x)]++;
			add(x,1);
		}
		for(i=0;i<n;i++)
			printf("%d\n",cnt[i]);
	}
}
