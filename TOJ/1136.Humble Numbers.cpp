#include<stdio.h>
int main()
{
    int hum[5843]={1},n,a,b,c,d,e,f,g,h,i;
    for(i=a=b=c=d=0;i<5843;)
    {
        e=hum[a]*2,f=hum[b]*3,g=hum[c]*5,h=hum[d]*7;
        hum[++i]=(e<f?e:f)<(g<h?g:h)?(e<f?e:f):(g<h?g:h);
        a+=hum[i]-e?0:1,b+=hum[i]-f?0:1,c+=hum[i]-g?0:1,d+=hum[i]-h?0:1;
    }
	while(scanf("%d",&n)&&n)
    {
        printf("The %d",n);
        if(n%10==1&&n/10%10-1)
            printf("st");
        else if(n%10==2&&n/10%10-1)
            printf("nd");
        else if(n%10==3&&n/10%10-1)
            printf("rd");
        else
            printf("th");
        printf(" humble number is %d.\n",hum[n-1]);
    }
}
