#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
    char a[1001],b[1001];
    int n,i,j,cnt,c[1001];
    while(scanf("%d",&n)!=EOF){
        stack<char>s;
        getchar();
        scanf("%s%s",a,b);
        for(cnt=i=j=0;i<n;i++){
            s.push(a[i]);
            c[cnt++]=1;
            while(j<n&&!s.empty())
                if(s.top()==b[j]){
                    s.pop();
                    c[cnt++]=0;
                    j++;
                }
                else break;
        }
        if(s.empty()){
            puts("Yes.");
            for(i=0;i<cnt;i++){
                if(c[i]) puts("in");
                else puts("out");
            }
        }
        else puts("No.");
        puts("FINISH");
    }
}
