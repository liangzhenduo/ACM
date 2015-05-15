/*
ID: liangzh7
LANG: C++
TASK: transform
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
char s[10][11],e[10][11],t[10][11];
int n,i,j,ans;
int t6(){
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(s[i][j]!=e[i][j])
                return 7;
    return 6;
}
int t53(){
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(t[i][j]!=e[n-1-j][i])
                return t6();
    return 5;
}
int t52(){
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(t[i][j]!=e[n-1-i][n-1-j])
                return t53();
    return 5;
}
int t51(){
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(t[i][j]!=e[j][n-1-i])
                return t52();
    return 5;
}
int t5(){
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            t[i][j]=s[i][n-1-j];
    return t51();
}
int t4(){
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(s[i][j]!=e[i][n-1-j])
                return t5();
    return 4;
}
int t3(){
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(s[i][j]!=e[n-1-j][i])
                return t4();
    return 3;
}
int t2(){
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(s[i][j]!=e[n-1-i][n-1-j])
                return t3();
    return 2;
}
int t1(){
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(s[i][j]!=e[j][n-1-i])
                return t2();
    return 1;
}

int main(){
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
	while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            scanf("%s",s[i]);
        for(i=0;i<n;i++)
            scanf("%s",e[i]);
        printf("%d\n",t1());
	}
}
