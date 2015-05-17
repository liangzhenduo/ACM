#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    while(1)
    {
        int m,p=11,q=0,key,k=0;
        string response0,response;
        while(cin >>m)
        {
            if(m==0)
            {
                k=1;
                break;
            }
            cin >>response0>>response;
            if(response=="on")
            {
                key=m;
                break;
            }
            else if(response=="high"&&m<p)
                p=m;
            else if(response=="low"&&m>q)
                q=m;
        }
        if(k==1)
            break;
        if(key<p&&key>q)
            cout <<"Stan may be honest"<<endl;
        else
            cout <<"Stan is dishonest"<<endl;
    }
    return 0;
}
