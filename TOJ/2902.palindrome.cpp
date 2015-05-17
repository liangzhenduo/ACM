#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char text[81];
    while(cin >>text)
    {
        int length=0,k=0;
        if(strlen(text)==1)
        {
            length=1;
            k=1;
        }
        else
            for(int i=1;i<=strlen(text);i++)
            {
                int m=1,n=1;
                if(i+1<strlen(text)&&text[i-1]==text[i+1])
                {
                    m=3;
                    for(int j=2;j<=i&&i+j<strlen(text);j++)
                    {
                        if(text[i-j]==text[i+j])
                            m+=2;
                        else
                            break;
                    }
                }
                if(text[i]==text[i-1])
                {
                    n=2;
                    for(int j=1;j<i&&i+j<strlen(text);j++)
                    {
                        if(text[i-1-j]==text[i+j])
                            n+=2;
                        else
                            break;
                    }
                }
                if(n<m)
                    n=m;
                if(length<n)
                {
                    length=n;
                    k=0;
                }
                if(n==length)
                    k++;
            }
        cout <<length<<" "<<k<<endl;
    }
    return 0;
}

