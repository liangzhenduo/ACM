#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    int n,i,j,k1,k2,c,c1,c2,a,b,p1[10],p2[10],f;
    while(scanf("%d",&n)!=EOF){
        queue<int> q1,q2;
        scanf("%d",&k1);
        for(i=0;i<k1;i++){
            scanf("%d",&p1[i]);
            q1.push(p1[i]);
        }
        scanf("%d",&k2);
        for(i=0;i<k2;i++){
            scanf("%d",&p2[i]);
            q2.push(p2[i]);
        }
        for(f=1,i=n;i>1;i--)
            f*=i;
        for(j=1;;j++){
            c1=q1.front();
            c2=q2.front();
            q1.pop();
            q2.pop();
            if(c1>c2){
                q1.push(c2);
                q1.push(c1);
            }
            else{
                q2.push(c1);
                q2.push(c2);
            }
            if(q1.empty()){
                printf("%d 2\n",j);
                break;
            }
            else if(q2.empty()){
                printf("%d 1\n",j);
                break;
            }
            if(j>f){
                puts("-1");
                break;
            }
        }
    }
}
