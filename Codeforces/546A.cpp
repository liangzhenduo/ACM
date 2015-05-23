#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    int k,n,w,i,j;
    while(scanf("%d%d%d",&k,&n,&w)!=EOF){
        for(j=0,i=1;i<=w;i++)
        j+=i;
        printf("%d\n",j*k-n>0?j*k-n:0);
    }
}
