#include <cstdio>
using namespace std;
int main(){
    int n,i,j;
    char c;
    while(scanf("%d",&n)!=EOF){
        i=0,j=0;
        getchar();
        while(n--){
            scanf("%c",&c);
            c=='1'?i++:j++;
        }
        printf("%d\n",i>j?i-j:j-i);
    }
}
