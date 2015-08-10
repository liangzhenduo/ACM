#include <cstdio>
#include <algorithm>
using namespace std;
int boa[8][7]={
    { 0, 2, 6,11,15,20,22}, // A
    { 1, 3, 8,12,17,21,23}, // B
    {10, 9, 8, 7, 6, 5, 4}, // C
    {19,18,17,16,15,14,13}, // D
};
const int rev[8]={ 5, 4, 7, 6, 1, 0, 3, 2};
const int cen[8]={ 6, 7, 8,11,12,15,16,17};
int a[24];
char ans[1000];
bool final(){
    for(int i=0;i<8;i++)
        if(a[cen[i]]!=a[cen[0]])
            return 0;
    return 1;
}
int diff(int target){
    int ans=0;
    for(int i=0;i<8;i++)
        if(a[cen[i]]!=target)
            ans++;
    return ans;
}
int h(){
  return min(min(diff(1),diff(2)),diff(3));
}
void move(int i){
    int tmp=a[boa[i][0]];
    for(int j=0;j<6;j++)
        a[boa[i][j]]=a[boa[i][j+1]];
    a[boa[i][6]]=tmp;
}
bool dfs(int d,int maxd){
    if(final()) {
        ans[d]='\0';
        return 1;
    }
    if(d+h()>maxd)
        return 0;
    for(int i=0;i<8;i++){
        ans[d]='A'+i;
        move(i);
        if(dfs(d+1, maxd))
            return 1;
        move(rev[i]);
    }
    return 0;
}
int main() {
    int i,j;
    for(i=4;i<8;i++)
        for(j=0;j<7;j++)
            boa[i][j]=boa[rev[i]][6-j];
    while(scanf("%d",&a[0])&&a[0]){
        for(i=1;i<24;i++)
            scanf("%d",&a[i]);
        if(final())
            printf("No moves needed\n");
        else
            for(i=1;;i++)
                if(dfs(0,i)){
                    printf("%s\n",ans);
                    break;
                }
        printf("%d\n",a[6]);
    }
}