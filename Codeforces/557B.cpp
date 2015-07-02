#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n,w,i,a[200001];
    while(scanf("%d%d",&n,&w)!=EOF){
        for(i=0;i<2*n;i++)
            scanf("%d",&a[i]);
        sort(a,a+2*n);
        double k=2*a[0]<a[n]?a[0]:a[n]/2.0;
        k*=(double)3*n;
        printf("%lf",k<w?k:w);
    }
}
