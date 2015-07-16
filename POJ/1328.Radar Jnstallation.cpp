#include <cstdio>
#include <cmath>
#include <algorithm>
struct Point{
    double l,r;
}point[1000];
bool cmp(Point p,Point q){
    return p.l<q.l;
}
int main(){
    int n,d,x,y,i,k,t=0;
    double j;
    while(scanf("%d%d",&n,&d)&&n+d){
        for(k=1,i=0;i<n;i++){
            scanf("%d%d",&x,&y);
            if(y>d||y<-d) k=-1;
            point[i].l=x-sqrt(d*d-y*y);
            point[i].r=x+sqrt(d*d-y*y);
        }
        if(k+1){
            std::sort(point,point+n,cmp);
            for(i=1,j=point[0].r;i<n;i++){
                if(j<point[i].l){
                    j=point[i].r;
                    k++;
                }
                else if(j>point[i].r)
                    j=point[i].r;
            }
        }
        printf("Case %d: %d\n",++t,k);
    }
}
