#include <cstdio>
using namespace std;
int main(){
    int n,a,b,c,d,e,f,i,j,k;
    while(scanf("%d%d%d%d%d%d%d",&n,&a,&b,&c,&d,&e,&f)!=EOF){
        for(i=a,j=c,k=e,n=n-i-j-k;n;n--){
            if(i<b)
                i++;
            else if(j<d)
                j++;
            else if(k<f)
                k++;
        }
        printf("%d %d %d\n",i,j,k);
    }
}
