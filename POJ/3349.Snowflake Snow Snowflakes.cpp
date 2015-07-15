#include <cstdio>
#include <vector>
#define mod 99997
using namespace std;
struct Snow{
    int arm[6],sum;
}snow[100000];
vector<Snow> hash[mod];
bool cmp(Snow p,Snow q){
    for(int i=0;i<6;i++)
        if(p.arm[0]==q.arm[i%6]&&p.arm[1]==q.arm[(i+1)%6]&&p.arm[2]==q.arm[(i+2)%6]&&
           p.arm[3]==q.arm[(i+3)%6]&&p.arm[4]==q.arm[(i+4)%6]&&p.arm[5]==q.arm[(i+5)%6]||
           p.arm[5]==q.arm[i%6]&&p.arm[4]==q.arm[(i+1)%6]&&p.arm[3]==q.arm[(i+2)%6]&&
           p.arm[2]==q.arm[(i+3)%6]&&p.arm[1]==q.arm[(i+4)%6]&&p.arm[0]==q.arm[(i+5)%6])
            return true;
    return false;
}
int main(){
    int n,i,j,k,flag;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(k=j=0;j<6;j++){
            scanf("%d",&snow[i].arm[j]);
            k+=snow[i].arm[j];
        }
        snow[i].sum=k;
        hash[k%mod].push_back(snow[i]);
    }
    for(flag=i=0;!flag&&i<mod;i++)
        for(j=0;!flag&&j<hash[i].size();j++)
            for(k=j+1;!flag&&k<hash[i].size();k++)
                if(hash[i][j].sum==hash[i][k].sum&&cmp(hash[i][j],hash[i][k]))
                    flag=1;
    puts(flag?"Twin snowflakes found.":"No two snowflakes are alike.");
}
