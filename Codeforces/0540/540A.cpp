#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    int n,i,j,k;
    char a[1001],b[1001];
    while(scanf("%d",&n)!=EOF){
        scanf("%s %s",a,b);
        for(k=i=0;i<n;i++){
            j=max(a[i],b[i])-min(a[i],b[i]);
            if(j>5) j=10-j;
            k+=j;
        }
        printf("%d\n",k);
    }
}
