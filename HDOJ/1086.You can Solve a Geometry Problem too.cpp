#include <cstdio>
struct Segment{
    double x1,y1,x2,y2;
}l[100];
bool intersect(Segment p,Segment q){
    double a=(p.x2-p.x1)*(q.y1-p.y1)-(p.y2-p.y1)*(q.x1-p.x1);
    double b=(p.x2-p.x1)*(q.y2-p.y1)-(p.y2-p.y1)*(q.x2-p.x1);
    if(a*b>0) return 0;
    double c=(q.x2-q.x1)*(p.y1-q.y1)-(q.y2-q.y1)*(p.x1-q.x1);
    double d=(q.x2-q.x1)*(p.y2-q.y1)-(q.y2-q.y1)*(p.x2-q.x1);
    if(c*d<=0) return 1;
    return 0;
}
int main(){
    int n,i,j,ans;
    while(scanf("%d",&n)&&n){
        for(i=0;i<n;i++)
            scanf("%lf%lf%lf%lf",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
        for(ans=i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                if(intersect(l[i],l[j])) ans++;
        printf("%d\n",ans);
    }
}
