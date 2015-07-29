#include <cstdio>
#include <cstring>
char rec[51][51];
int main(){
    int t,n,i,j,flag,ans,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(rec,0,sizeof(rec));
        for(ans=i=0;i<n;i++)
            scanf("%s",rec[i]);
        m=strlen(rec[0]);
        for(i=0;i<n;i++){
            flag=0;
            for(j=0;i+j<n&&j<m;j++){
                if(flag==0&&(rec[i+j][j]=='R'||rec[i+j][j]=='G'))
                    flag=1,ans++;
                else if(flag==1&&!(rec[i+j][j]=='R'||rec[i+j][j]=='G'))
                    flag=0;
            }
        }
        for(j=1;j<m;j++){
            flag=0;
            for(i=0;i<n&&j+i<m;i++){
                if(flag==0&&(rec[i][j+i]=='R'||rec[i][j+i]=='G'))
                    flag=1,ans++;
                else if(flag==1&&!(rec[i][j+i]=='R'||rec[i][j+i]=='G'))
                    flag=0;
            }
        }
        for(i=0;i<n;i++){
            flag=0;
            for(j=m-1;j>=0&&m-1+i-j>=0;j--){
                if(flag==0&&(rec[m-1+i-j][j]=='B'||rec[m-1+i-j][j]=='G'))
                    flag=1,ans++;
                else if(flag==1&&!(rec[m-1+i-j][j]=='B'||rec[m-1+i-j][j]=='G'))
                    flag=0;
            }
        }
        for(j=m-2;j>=0;j--){
            flag=0;
            for(i=0;i<=n&&j-i>=0;i++){
                if(flag==0&&(rec[i][j-i]=='B'||rec[i][j-i]=='G'))
                    flag=1,ans++;
                else if(flag==1&&!(rec[i][j-i]=='B'||rec[i][j-i]=='G'))
                    flag=0;
            }
        }
        printf("%d\n",ans);
    }
}
