#include <cstdio>
#include <cstring>
int next[1001];
char a[1001],b[1001];
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
            cnt++,j=0;
    }
    return cnt;
}
int main(){
    while(scanf("%s",a)&&a[0]!='#'){
        scanf("%s",b);
        printf("%d\n",kmp());
    }
}
