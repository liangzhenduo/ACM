#include <iostream>
#include <cstring>
int used[200001],day[200001],store[200001];
using namespace std;
int main()
{
    int m,a,b;
    while(cin >>m>>a>>b)
    {
        memset(used,0,200001);
        memset(day,0,200001);
        memset(store,0,200001);
        if(a>=b)
            cout <<a-b<<endl;
        else
        {
            int tail=0,head=0,k;
            used[a]=1;
            store[tail++]=a;
            while(head<tail)
            {
                k=store[head++];
                if(k==b)
                    break;
                if(m<=2*k&&used[m]==0)
                {
                    day[m]=day[k]+1;
                    store[tail++]=m;
                    used[m]=1;
                }
                if(m>2*k&&used[2*k]==0)
                {
                    day[k*2]=day[k]+1;
                    store[tail++]=k*2;
                    used[k*2]=1;
                }
                if(k+1<=m&&used[k+1]==0)
                {
                    day[k+1]=day[k]+1;
                    store[tail++]=k+1;
                    used[k+1]=1;
                }
                if(k>1&&used[k-1]==0)
                {
                    day[k-1]=day[k]+1;
                    store[tail++]=k-1;
                    used[k-1]=1;
                }
            }
            cout <<day[b]<<endl;
        }
    }
    return 0;
}
