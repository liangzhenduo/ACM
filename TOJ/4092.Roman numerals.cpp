#include <iostream>
#include <cstring>
using namespace std;
char* dig[10]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
char* ten[10]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
char* hun[10]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
int main()
{
    int t,n,m,k;
    cin >>t;
    while(t--)
    {
        cin >>n;
        k=1000000000;
        while(k/=1000)
        {
            m=n/k;
            if(!m)
                continue;
            if(k>1000)
                cout <<"(("<<hun[m%1000/100]<<ten[m%100/10]<<dig[m%10]<<"))";
            else if(k==1000)
                cout <<"("<<hun[m%1000/100]<<ten[m%100/10]<<dig[m%10]<<")";
            else
                cout <<hun[m%1000/100]<<ten[m%100/10]<<dig[m%10]<<endl;
        }
    }
    return 0;
}
