#include <iostream>
#include <cstring>
using namespace std;
int mod[1000000];
int main()
{
    int n,g,i,j,k,sin[300];
    cin >>n;
    while(n--)
    {
        cin >>g;
        for(i=0;i<g;i++)
            cin >>sin[i];
        for(i=g;;i++)
        {
            memset(mod,0,sizeof(int)*i);
            k=0;
            for(j=0;j<g;j++)
            {
                if(mod[sin[j]%i])
                    break;
                else
                {
                    mod[sin[j]%i]++;
                    k++;
                }
            }
            if(g==k)
                break;
        }
        cout <<i<<endl;
    }
    return 0;
}

