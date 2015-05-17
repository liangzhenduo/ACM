#include <iostream>
using namespace std;
int main()
{
    int d,m;
    while(cin >>d>>m)
    {
        if(m==2)
            d+=31;
        else if(m==3)
            d+=59;
        else if(m==4)
            d+=90;
        else if(m==5)
            d+=120;
        else if(m==6)
            d+=151;
        else if(m==7)
            d+=181;
        else if(m==8)
            d+=212;
        else if(m==9)
            d+=243;
        else if(m==10)
            d+=273;
        else if(m==11)
            d+=304;
        else if(m==12)
            d+=334;
        if(d%7==1)
            cout <<"Thursday"<<endl;
        else if(d%7==2)
            cout <<"Friday"<<endl;
        else if(d%7==3)
            cout <<"Saturday"<<endl;
        else if(d%7==4)
            cout <<"Sunday"<<endl;
        else if(d%7==5)
            cout <<"Monday"<<endl;
        else if(d%7==6)
            cout <<"Tuesday"<<endl;
        else if(d%7==0)
            cout <<"Wednesday"<<endl;
    }
    return 0;
}

