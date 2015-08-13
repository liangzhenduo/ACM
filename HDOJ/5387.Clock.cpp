#include <cstdio>
#include <iostream>
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
	int t,h,m,s,a,b,c,d,e,f,j,k,l,o,p,q;
	scanf("%d",&t);
	while(t--){
		scanf("%d:%d:%d",&h,&m,&s);
		h%=12;
		a=30*h*120+60*m+s;
		b=6*m*120+12*s;
		c=6*s*120;
		d=abs(a-b);if(d>21600) d=43200-d;
		e=abs(a-c);if(e>21600) e=43200-e;
		f=abs(b-c);if(f>21600) f=43200-f;
		h=gcd(d,120);j=d/h;o=120/h;
		m=gcd(e,120);k=e/m;p=120/m;
		s=gcd(f,120);l=f/s;q=120/s;
		if(o==1) printf("%d ",j);
		else printf("%d/%d ",j,o);
		if(p==1) printf("%d ",k);
		else printf("%d/%d ",k,p);
		if(q==1) printf("%d ",l);
		else printf("%d/%d ",l,q);
		puts("");
	}
}