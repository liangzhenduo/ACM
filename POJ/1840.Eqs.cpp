#include <cstdio>
#include <vector>
#define mod 9997
using namespace std;
int main(){
    int a[5],i,j,k,tmp,ans,cube[101];
    for(i=0;i<101;i++) cube[i]=(i-50)*(i-50)*(i-50);
    while(scanf("%d",&a[0])!=EOF){
        vector<int> frt[20000],bhd[20000];
        for(i=1;i<5;i++)
            scanf("%d",&a[i]);
        for(i=0;i<101;i++){
            if(i==50) continue;
            for(j=0;j<101;j++){
                if(j==50) continue;
                tmp=-a[0]*cube[i]-a[1]*cube[j];
                frt[tmp%mod+mod].push_back(tmp);
            }
        }
        for(i=0;i<101;i++){
            if(i==50) continue;
            for(j=0;j<101;j++){
                if(j==50) continue;
                for(k=0;k<101;k++){
                    if(k==50) continue;
                    tmp=a[2]*cube[i]+a[3]*cube[j]+a[4]*cube[k];
                    if(tmp>12500000||tmp<-12500000) continue;
                    bhd[tmp%mod+mod].push_back(tmp);
                }
            }
        }
        for(ans=i=0;i<2*mod;i++)
            for(j=0;j<frt[i].size();j++)
                for(k=0;k<bhd[i].size();k++)
                    if(frt[i][j]==bhd[i][k])
                        ans++;
        printf("%d\n",ans);
    }
}
