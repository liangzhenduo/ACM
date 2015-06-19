#include <cstdio>
using namespace std;
int main(){
    int n,a,b,c,d,i,j;
    while(scanf("%d",&n)!=EOF){
        for(j=i=0;i<n;i++){
            scanf("%d%d%d%d",&a,&b,&c,&d);
            j+=(c-a+1)*(d-b+1);
        }
        printf("%d\n",j);
    }
}
