#include <cstdio>
int x,y;
int egcd(int a,int b){
    if(b==0){
        x=1,y=0;
        return a;
    }
    int gcd=egcd(b,a%b),tmp=x;
    x=y,y=tmp-a/b*x;
    return gcd;
}
int main(){
    int t,n,m,i,j,a[10],b[10],flag,gcd,tmp;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
            scanf("%d",&a[i]);
        for(i=0;i<m;i++)
            scanf("%d",&b[i]);
        for(flag=0,i=1;i<m;i++){
            gcd=egcd(a[0],a[i]);
            if((b[i]-b[0])%gcd){
                flag=1;
                break;
            }
            tmp=a[i]/gcd;
            x=x*(b[i]-b[0])/gcd;
            x=(x%tmp+tmp)%tmp;
            b[0]+=a[0]*x;
            a[0]=a[0]/gcd*a[i];
            b[0]=(b[0]%a[0]+a[0])%a[0];
        }
        if(flag||n<b[0]) puts("0");
        else printf("%d\n",(n-b[0])/a[0]+1-(b[0]?0:1));
    }
}
