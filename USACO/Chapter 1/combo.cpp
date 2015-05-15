/*
ID: liangzh7
LANG: C++
TASK: combo
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	freopen("combo.in","r",stdin);
	freopen("combo.out","w",stdout);
	int n,f[3],m[3],i,ans,p,q,r;
	while(scanf("%d",&n)!=EOF){
        for(i=0;i<3;i++)
            scanf("%d",&f[i]);
        for(i=0;i<3;i++)
            scanf("%d",&m[i]);
        if(n<5) ans=n*n*n;
        else{
            p=2*abs(f[0]-m[0])<n?abs(f[0]-m[0]):n-abs(f[0]-m[0]);
            q=2*abs(f[1]-m[1])<n?abs(f[1]-m[1]):n-abs(f[1]-m[1]);
            r=2*abs(f[2]-m[2])<n?abs(f[2]-m[2]):n-abs(f[2]-m[2]);
            ans=250;
            if(p<5&&q<5&&r<5)
                ans-=(5-p)*(5-q)*(5-r);
        }
        printf("%d\n",ans);
	}
}
