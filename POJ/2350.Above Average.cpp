#include <cstdio>
using namespace std;
int main(){
    int n,m,k,i,j,grd[1001];
    double avg,abv;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        for(k=i=0;i<m;i++){
            scanf("%d",&grd[i]);
            k+=grd[i];
        }
        for(avg=k/m,abv=i=0;i<m;i++)
            if(grd[i]>avg)
                abv++;
        printf("%.3f",100*abv/m);
        puts("%");
    }
}
