#include <cstdio>
#include <cstring>
int main(){
    int k,e,t=0,len[20],num[20],i,j,l,m;
    char key[20][21],exc[20][71];
    while(scanf("%d%d",&k,&e)!=EOF){
        for(i=0;i<k;i++){
            scanf("%s",key[i]);
            len[i]=strlen(key[i]);
        }
        getchar();
        memset(num,0,sizeof(num));
        for(m=i=0;i<e;i++){
            gets(exc[i]);
            for(j=0;j<strlen(exc[i]);j++)
                if(!j||exc[i][j-1]<65)
                    for(l=0;l<k;l++)
                        if(!strncasecmp(key[l],exc[i]+j,len[l])&&exc[i][j+len[l]]<65){
                            num[i]++;
                            break;
                        }
            m=num[i]>m?num[i]:m;
        }
        printf("Excuse Set #%d\n",++t);
        for(i=0;i<e;i++)
            if(num[i]==m) puts(exc[i]);
        puts("");
    }
}
