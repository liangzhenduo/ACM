#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int m,n,k,v[1001];
    char w[1001][17],s[17];
    while(cin >>m>>n)
    {
        for(int i=0;i<m;i++)
            cin >>w[i]>>v[i];
        while(n--)
        {
            k=0;
            while(cin >>s&&s[0]!='.')
                for(int j=0;j<m;j++)
                    if(!strcmp(s,w[j]))
                    {
                        k+=v[j];
                        break;
                    }
            cout <<k<<endl;
        }
    }
    return 0;
}
