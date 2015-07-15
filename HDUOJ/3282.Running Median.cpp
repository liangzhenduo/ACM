#include <cstdio>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> > maxi;
priority_queue<int,vector<int>,less<int> > mini;
void insert(int tmp){
    if(maxi.empty()){
        maxi.push(tmp);
        return;
    }
    if(tmp>maxi.top()) maxi.push(tmp);
    else mini.push(tmp);
    while(maxi.size()<mini.size())
        maxi.push(mini.top()),mini.pop();
    while(maxi.size()>mini.size()+1)
        mini.push(maxi.top()),maxi.pop();
}
int main(){
    int p,n,m,i,j,tmp;
    scanf("%d",&p);
    while(p--){
        while(!maxi.empty()) maxi.pop();
        while(!mini.empty()) mini.pop();
        scanf("%d%d",&n,&m);
        printf("%d %d\n",n,m/2+1);
        for(j=0,i=1;i<=m;i++){
            scanf("%d",&tmp);
            insert(tmp);
            if(i%2) printf(++j%10&&i<m?"%d ":"%d\n",maxi.top());
        }
    }
}
