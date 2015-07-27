#include <cstdio>
#include <cstring>
int next[10001];
char a[1000001],b[10001];
void nxt(){
    int len=strlen(b),i=0,j=-1;
    next[0]=-1;
    while(i<len)
        if(j==-1||b[i]==b[j])
            i++,j++,next[i]=j;
        else
            j=next[j];
}
int kmp(){
    nxt();
    int n=strlen(a),m=strlen(b),i=0,j=0,cnt=0;
    while(i<n&&j<m){
        if(j==-1||a[i]==b[j])
            i++,j++;
        else
            j=next[j];
        if(j==m)
            cnt++,j=next[j];
    }
    return cnt;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s%s",b,a);
        printf("%d\n",kmp());
    }
}
