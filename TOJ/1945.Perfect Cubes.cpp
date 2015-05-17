#include <iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    for(a=6;a<=200;a++)
        for(b=2;b<a-2;b++)
            for(c=b+1;c<a-1;c++)
                if(b<=c)
                    for(d=c+1;d<a;d++)
                        if(c<=d&&a*a*a==b*b*b+c*c*c+d*d*d)
                            cout <<"Cube = "<<a<<", Triple = ("<<b<<","<<c<<","<<d<<")"<<endl;
    return 0;
}

