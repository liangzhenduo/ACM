#include <cstdio>
#include <map>
using namespace std;
int main(){
	map<int,double> f;
	f[1]=1312.0;
	f[2]=2372.3;
	f[3]=520.2;
	f[4]=932;
	f[5]=800.6;
	f[6]=1086.5;
	f[7]=1402.3;
	f[8]=1313.9;
	f[9]=1681.0;
	f[10]=2080.7;
	f[11]=495.8;
	f[12]=737.7;
	f[13]=577.5;
	f[14]=786.5;
	f[15]=1011.8;
	f[16]=999.6;
	f[17]=1215.2;
	f[18]=1520.6;
	f[35]=1139.9;
	f[36]=1350.8;
	f[53]=1008.4;
	f[54]=1170.4;
	f[85]=890;
	f[86]=1037;
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
		puts(f[a]>f[b]?"FIRST BIGGER":"SECOND BIGGER");
}