#include <cstdio>
#include <cstring>
int main(){
    int t,n,q,c,a,b[2001],i,sum;
    scanf("%d",&t);
    while(t--){
        memset(b,0,sizeof(b));
        scanf("%d",&n);
        while(n--)
            scanf("%d",&a),b[a]++;
        scanf("%d",&q);
        while(q--){
            scanf("%d",&c);
            if(c>2000) sum=0;
            else
                for(sum=0,i=0;i<=c&&i<1001;i++)
                    if(2*i==c)
                        sum+=b[i]*(b[i]-1);
                    else
                        sum+=b[i]*b[c-i];
            printf("%d\n",sum);
        }
    }
}