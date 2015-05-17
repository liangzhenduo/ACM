#include <cstdio>
int main(){
    int n,a,e,o,i;
    while(scanf("%d",&n)&&n){
        for(e=o=i=0;i<n;i++){
            scanf("%d",&a);
            if(a%2) o++;
            else e++;
        }
        if(o<e&&!(n%2)) puts("While the priest climbs a post, the devil climbs ten.");
        else if(o>e&&n%2) puts("Justice will prevail over evil.");
        else puts("I love this world.");
    }
}
