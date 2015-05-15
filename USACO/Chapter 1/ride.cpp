/*
ID: liangzh7
LANG: C++
TASK: ride
*/
#include <cstdio>
#include <cstring>
int main(){
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    int a,b,i;
    char s[7],t[7];
    while(scanf("%s %s",s,t)!=EOF){
        for(a=1,i=0;i<strlen(s);i++)a*=(s[i]-64);
        for(b=1,i=0;i<strlen(t);i++)b*=(t[i]-64);
        if(a%47==b%47) puts("GO");
        else puts("STAY");
    }
    return 0;
}
