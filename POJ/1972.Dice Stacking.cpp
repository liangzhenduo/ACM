#include <cstdio>
int main(){
    int t,n,i,j,k,l;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int a[10001][6],b[6]={0};
        for(i=0;i<n;i++)
            for(j=0;j<6;j++){
                k=j;
                if(j==3||j==4) k=7-j;
                scanf("%d",&a[i][k]);
            }
        for(l=0;l<6;l++){
            if(a[0][l]!=6&&a[0][5-l]!=6) b[l]+=6;
            else if(a[0][l]==6&&a[0][5-l]==5||a[0][l]==5&&a[0][5-l]==6) b[l]+=4;
            else b[l]+=5;
            k=5-l;
            for(i=1;i<n;i++)
                for(j=0;j<6;j++)
                    if(a[i][j]==a[i-1][k]){
                        if(a[i][j]!=6&&a[i][5-j]!=6) b[l]+=6;
                        else if(a[i][j]==6&&a[i][5-j]==5||a[i][j]==5&&a[i][5-j]==6) b[l]+=4;
                        else b[l]+=5;
                        k=5-j;
                        break;
                    }
        }
        k=b[0];
        for(l=1;l<6;l++)
            if(k<b[l]) k=b[l];
        printf("%d\n",k);
    }
}
