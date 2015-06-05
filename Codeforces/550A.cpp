#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    int a,b,i;
    char s[100001];
    bool u[100001];
    while(scanf("%s",s)!=EOF){
        memset(u,0,sizeof(u));
        for(a=b=i=0;!(a&&b)&&i<strlen(s)-1;i++){
            if(u[i]) continue;
            if(!a&&s[i]=='A'&&s[i+1]=='B')
                a++,u[i]=u[i+1]=1;
            else if(!b&&s[i]=='B'&&s[i+1]=='A')
                b++,u[i]=u[i+1]=1;
        }
        if(a&&b){
            puts("YES");
            continue;
        }
        memset(u,0,sizeof(u));
        for(a=b=0,i=strlen(s)-1;!(a&&b)&&i>0;i--){
            if(u[i]) continue;
            if(!a&&s[i]=='A'&&s[i-1]=='B')
                a++,u[i]=u[i-1]=1;
            else if(!b&&s[i]=='B'&&s[i-1]=='A')
                b++,u[i]=u[i-1]=1;
        }
        if(a&&b) puts("YES");
        else puts("NO");
    }
}
