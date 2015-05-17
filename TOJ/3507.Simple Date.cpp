#include <stdio.h>
#include <algorithm>
struct Date{
    int y,m,d;
}dat1,dat2;
int main()
{
    int t,mon[12]={31,28,31,30,31,30,31,31,30,31,30,31},i,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d/%d/%d%d/%d/%d",&dat1.y,&dat1.m,&dat1.d,&dat2.y,&dat2.m,&dat2.d);
        if(dat1.y>dat2.y||!(dat1.y-dat2.y)&&dat1.m>dat2.m||!(dat1.y-dat2.y)&&!(dat1.m-dat2.m)&&dat1.d>dat2.d)
            std::swap(dat1,dat2);
        k=365*(dat2.y-dat1.y)+(dat2.d-dat1.d);
        for(i=dat1.y+1;i<dat2.y;i++)
            if(!(i%4)&&i%100||!(i%400))
                k++;
        if((!(dat1.y%4)&&dat1.y%100||!(dat1.y%400))&&dat1.m<3&&dat1.d<30&&(dat2.m>2||dat2.y>dat1.y)) k++;
        if(dat1.y<dat2.y&&(!(dat2.y%4)&&dat2.y%100||!(dat2.y%400))&&dat2.m>2) k++;
        if(dat2.m<dat1.m)
        {
            k-=365;
            dat2.m+=12;
        }
        for(i=dat1.m;i<dat2.m;i++)
            k+=mon[(i-12?i%12:12)-1];
        printf("%d\n",k);
    }
}

