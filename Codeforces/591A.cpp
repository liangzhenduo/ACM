#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	double l,p,q;
	while(scanf("%lf%lf%lf",&l,&p,&q)!=EOF){
		printf("%f\n",l*p/(p+q));
	}
}