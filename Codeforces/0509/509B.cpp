#include <stdio.h>
int main(){
    int n,k,i,j,pile[101],max,min;
    while(scanf("%d%d",&n,&k)!=EOF){
        for(max=0,min=65536,i=0;i<n;i++){
            scanf("%d",&pile[i]);
            max=pile[i]>max?pile[i]:max;
            min=pile[i]<min?pile[i]:min;
        }
        if(max-min>k)
            puts("NO");
        else{
            puts("YES");
            for(i=0;i<n;i++){
                for(j=1;j<pile[i];j++)
                    printf("%d ",j%k?j%k:k);
                printf("%d\n",j%k?j%k:k);
            }
        }
    }
}
