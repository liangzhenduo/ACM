/*
ID: liangzh7
LANG: C++
TASK: friday
*/
#include <cstdio>
bool leap(int year){
    return (year%4==0&&year%100!=0)||(year%400==0);
}
int main(){
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
	int i,j,k,n,mon[]={31,28,31,30,31,30,31,31,30,31,30,31};
	while(scanf("%d",&n)!=EOF){
        int week[7]={0};
        for(k=2,i=1900;i<1900+n;i++){
            if(leap(i)) mon[1]=29;
            else mon[1]=28;
            for(j=0;j<12;j++){
                week[(k+13)%7]++;
                k+=mon[j];
            }
        }
        for(i=1;i<7;i++) printf("%d ",week[i]);
        printf("%d\n",week[0]);
	}
}
