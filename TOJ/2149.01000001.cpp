#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int t;
    cin >>t;
    for(int l=1;l<=t;l++)
    {
        char a[81],b[81];
        int result[82]={0},k,m,flag=0,p=0,q=0;
        cin >>a>>b;
        for(int i=0;i<strlen(a);i++)
            p+=(a[i]-48);
        for(int i=0;i<strlen(b);i++)
            p+=(b[i]-48);
        if(p==0&&q==0)
        {
            cout <<l<<" "<<0<<endl;
            continue;
        }
        if(strlen(a)>strlen(b))
        {
            m=strlen(a);
            k=strlen(a)-strlen(b);
            for(int i=strlen(a)-1;i>=0;i--)
            {
                if(i>=k)
                    b[i]=b[i-k];
                else
                    b[i]='0';
            }
        }
        else
        {
            m=strlen(b);
            k=strlen(b)-strlen(a);
            for(int i=strlen(b)-1;i>=0;i--)
            {
                if(i>=k)
                    a[i]=a[i-k];
                else
                    a[i]='0';
            }
        }
        for(int j=1;j<=m;j++)
        {
            if(a[m-j]+b[m-j]==97&&result[j-1]==0)
                result[j-1]=1;
            else if(a[m-j]+b[m-j]==97&&result[j-1]==1)
            {
                result[j-1]=0;
                result[j]=1;
            }
            else if(a[m-j]+b[m-j]==98&&result[j-1]==0)
            {
                result[j-1]=0;
                result[j]=1;
            }
            else if(a[m-j]+b[m-j]==98&&result[j-1]==1)
            {
                result[j-1]=1;
                result[j]=1;
            }
        }
        cout <<l<<" ";
        for(int i=81;i>=0;i--)
        {
            if(result[i]==1)
                flag=1;
            if(flag)
                cout <<result[i];
        }
        cout <<endl;
    }
    return 0;
}

