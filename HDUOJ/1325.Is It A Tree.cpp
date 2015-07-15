#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
int fa[1000],root;
set<int> node;
int fi(int x,int o){
    if(fa[x]==o) return -1;
    return fa[x]?fa[x]=fi(fa[x],o):x;
}
int main(){
    int t=0,m,n,i,j,flag;
    while(++t){
        memset(fa,0,sizeof(fa));
        node.clear();
        j=0,flag=1;
        while(scanf("%d%d",&m,&n)&&n>0){
            node.insert(m),node.insert(n),j++;
            if(fa[n]){
                flag=0;
                continue;
            }
            fa[n]=m;
        }
        if(n<0) break;
        if(node.size()>0&&j!=node.size()-1) flag=0;  //n-1 edges
        if(node.size()>0&&flag){  //1 root
            set<int>::iterator it;
            for(i=0,it=node.begin();it!=node.end();++it)
                if(!fa[*it]) root=*it,i++;
            if(i!=1) flag=0;
            for(it=node.begin();flag&&it!=node.end();++it)
                if(fi(*it,*it)-root) flag=0;
        }
        printf("Case %d ",t);
        puts(flag?"is a tree.":"is not a tree.");
    }
}
