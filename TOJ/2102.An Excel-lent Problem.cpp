#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

    char change(int m)
    {
        char k;
        if(m%26==0)
            k='Z';
        else
            k=m%26+64;
        return k;
    }

int main()
{
    char r,c;
    long long n,m;
    while(cin >>r>>n>>c>>m&&m+n)
    {
        string sheet;
        sheet+=change(m);
        while(m>26)
        {
            if(m%26)
                m/=26;
            else
            {
                m/=26;
                m--;
            }
            sheet+=change(m);
        }
        reverse(sheet.begin(),sheet.end());
        cout <<sheet<<n<<endl;
    }
    return 0;
}

