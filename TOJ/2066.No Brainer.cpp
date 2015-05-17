#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    char x[102],y[102];
    cin >>n;
    for(int i=0;i<n;i++)
    {
        int h=-1;
        cin >>x>>y;
        if(strlen(x)==strlen(y))
        for(int j=0;j<strlen(x);j++)
        {
            if(x[j]==y[j])
                continue;
            else if(x[j]<y[j])
            {
                h=0;
                break;
            }
            else if(x[j]>y[j])
            {
                h=1;
                break;
            }
        }
        else if(strlen(x)<strlen(y))
            h=0;
        else if(strlen(x)>strlen(y))
            h=1;

        if(h==0)
            cout <<"NO BRAINS"<<endl;
        else
            cout <<"MMM BRAINS"<<endl;
    }
    return 0;
}

