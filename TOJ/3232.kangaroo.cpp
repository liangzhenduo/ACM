#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    while(cin >>a>>b>>c)
    {
        int k=0;
        if(c-b>b-a)
            while(c-b>=2)
            {
                a=b;
                b++;
                k++;
            }
        else
            while(b-a>=2)
            {
                c=b;
                b--;
                k++;
            }
        cout <<k<<endl;
    }
    return 0;
}

