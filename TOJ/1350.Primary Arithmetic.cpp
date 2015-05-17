#include <iostream>
using namespace std;
int main()
{
    long int x,y;
    while(cin >>x>>y)
    {
        if(x==0&&y==0)break;
        int z;
        int k=0,w=0;
        for(int i=0;i<11;i++)
        {
            z=x%10+y%10+w;
            if(z>=10)
            {
                w=z/10;
                k++;
            }
            x=x/10;
            y=y/10;
        }
        if(k==0)
            cout <<"No carry operation."<<endl;
        else if(k==1)
            cout <<k<<" carry operation."<<endl;
        else
            cout <<k<<" carry operations."<<endl;
    }
    return 0;
}

