#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    cin >>n;
    char s[100],t[100];
    for(int k=0;k<n;k++)
    {
        cin >>s>>t;
        int e=0,f=0,i,j,result=1,p=0,q=0;
        for(i=0;i<strlen(t);i++)
        {
            for(j=e;j<strlen(s);j++)
                if(t[i]==s[j])
                {
                    e=j+1;
                    p++;
                    break;
                }
            if(p==strlen(t))
                break;
            if(j==strlen(s)&&i<strlen(t))
            {
                result--;
                break;
            }
        }
        for(i=strlen(t)-1;i>=0;i--)
        {
            for(j=f;j<strlen(s);j++)
                if(t[i]==s[j])
                {
                    f=j+1;
                    q++;
                    break;
                }
            if(q==strlen(t))
                break;
            if(j==strlen(s)&&i>=0)
            {
                result--;
                break;
            }

        }
        if(result==-1)
            cout <<"NO"<<endl;
        else
            cout <<"YES"<<endl;
    }
    return 0;
}

