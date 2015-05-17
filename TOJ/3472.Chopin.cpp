#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int t;
    char a[101],b[101];
    cin >>t;
    while(t--)
    {
        cin >>a>>b;
        int k=0,l=0;
        for(int i=0;i<strlen(b);i++)
            for(int j=l;j<strlen(a);j++)
                if(a[j]==b[i])
                {
                    k++;
                    l=j+1;
                    break;
                }
        cout <<(k==strlen(b)?"yes":"no")<<endl;
    }
}
