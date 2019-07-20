#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Seg{
    double y1,y2;
}seg[100005];
bool cmp(Seg p,Seg q){
    if(p.y1==q.y1) return p.y2<q.y2;
    return p.y1<q.y1;
}
int main(){
    int n,i,j,m;
    double x1,x2,k,b;
    while(scanf("%d",&n)!=EOF){
        scanf("%lf%lf",&x1,&x2);
        for(i=0;i<n;i++){
            scanf("%lf%lf",&k,&b);
            seg[i].y1=k*x1+b;
            seg[i].y2=k*x2+b;
        }
        sort(seg,seg+n,cmp);
        for(j=0,i=1;i<n;i++)
            if(seg[i].y2<seg[i-1].y2&&seg[i].y1>seg[i-1].y1){
                j=1;break;
            }
        puts(j?"Yes":"No");
    }
}