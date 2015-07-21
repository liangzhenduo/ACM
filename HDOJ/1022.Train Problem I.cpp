#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int main(){
    char a[1001],b[1001];
    int n,i,j,cnt,c[1001];
    while(scanf("%d",&n)!=EOF){
        stack<char> s;
        queue<char> q;
        vector<int> v;
        getchar();
        scanf("%s%s",a,b);
        for(i=0;i<n;i++) q.push(b[i]);
        for(i=0;i<n;i++){
            s.push(a[i]);
            v.push_back(1);
            while(!s.empty()&&s.top()==q.front())
                s.pop(),q.pop(),v.push_back(0);
        }
        if(!s.empty()) puts("No.");
        else{
            puts("Yes.");
            for(i=0;i<2*n;i++) puts(v[i]?"in":"out");
        }
        puts("FINISH");
    }
}
