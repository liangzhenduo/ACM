#include <cstdio>
#include <cstring>
int next[100001];
char str[100001];
void nxt(){
    int len=strlen(str),i=0,j=-1;
    next[0]=-1;
    while(i<len)
        if(j==-1||str[i]==str[j])
            if(str[++i]==str[++j])
                next[i]=next[j];
            else next[i]=j;
        else j=next[j];
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        nxt();
        int n=strlen(str),ans=n-next[n];
        if(ans-n&&!(n%ans)) ans=0;
        else ans-=n%ans;
        printf("%d\n",ans);
    }
}
