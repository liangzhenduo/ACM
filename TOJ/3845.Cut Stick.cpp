#include <iostream>
using namespace std;
int main()
{
    int l,n,i;
    while(cin >>l)
    {
        int a=0,b=1,c,k;
        for(k=1;;k++)
        {
            l-=b;
            if(l<(a+b))
                break;
            c=a;
            a=b;
            b+=c;
        }
        cout <<k<<endl;
    }
    return 0;
}

