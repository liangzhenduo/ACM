#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    int n,i,j,k,ba[3001];
    while(scanf("%d",&n)!=EOF){
        for(k=i=0;i<n;i++)
            scanf("%d",&ba[i]);
        sort(ba,ba+n);
        for(i=1;i<n;i++){
            if(ba[i]==ba[i-1]){
                ba[i]++;
                k++;
            }
            else if(ba[i]<ba[i-1]){
                k+=(ba[i-1]-ba[i]+1);
                ba[i]=ba[i-1]+1;
            }
        }
        printf("%d\n",k);
    }
}
