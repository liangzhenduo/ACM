#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> pri;
int prime[5000001]={0};
int num[5000001]={0};
bool isPrime(int k){
    for(int j=2;j*j<=k;j++)
        if(k%j==0)
            return false;
    return true;
}
int main(){
    int t,n,i,j,k,v,a,b;
    for(i=2;i<5000001;i++)
        if(isPrime(i)) pri.push_back(i),prime[i]=1;
    for(i=1;i<5000001;i++){
            for(v=i,k=j=0;v>1;j++){
                if(prime[v]){
                    k++;
                    break;
                }
                while(v%pri[j]==0){
                    v/=pri[j];
                    k++;
                }
            }
        num[i]=num[i-1]+k;
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        printf("%d\n",num[a]-num[b]);
    }
}
