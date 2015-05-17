#include <iostream>
using namespace std;

    void year(int n)
    {
        for(int i=0;;i++)
        {
            if(n<0)
            {
                cout <<1999+i;
                break;
            }
            if(i%400==0||i%4==0&&i%100!=0)
                n=n-366;
            else
                n=n-365;
        }
    }
    void month(int n)
    {
        int m=n,y=0;
        for(int i=0;;i++)
        {
            if(n<0)
            {
                y=1999+i;
                break;
            }

            if(i%400==0||i%4==0&&i%100!=0)
                n=n-366;
            else
                n=n-365;

            if(n>=0)
                m=n;
        }
        if(y%400==0||y%4==0&&y%100!=0)
        {
            if(m<31)
                cout <<"01";
            else if(m<60)
                cout <<"02";
            else if(m<91)
                cout <<"03";
            else if(m<121)
                cout <<"04";
            else if(m<152)
                cout <<"05";
            else if(m<182)
                cout <<"06";
            else if(m<213)
                cout <<"07";
            else if(m<244)
                cout <<"08";
            else if(m<274)
                cout <<"09";
            else if(m<305)
                cout <<"10";
            else if(m<335)
                cout <<"11";
            else if(m<366)
                cout <<"12";
        }
        else
        {
            if(m<31)
                cout <<"01";
            else if(m<59)
                cout <<"02";
            else if(m<90)
                cout <<"03";
            else if(m<120)
                cout <<"04";
            else if(m<151)
                cout <<"05";
            else if(m<181)
                cout <<"06";
            else if(m<212)
                cout <<"07";
            else if(m<243)
                cout <<"08";
            else if(m<273)
                cout <<"09";
            else if(m<304)
                cout <<"10";
            else if(m<334)
                cout <<"11";
            else if(m<365)
                cout <<"12";
        }
    }
    void day(int n)
    {
        int m=n,y=0;
        for(int i=0;;i++)
        {
            if(n<0)
            {
                y=1999+i;
                break;
            }

            if(i%400==0||i%4==0&&i%100!=0)
                n=n-366;
            else
                n=n-365;

            if(n>=0)
                m=n;
        }
        if(y%400==0||y%4==0&&y%100!=0)
        {
            if(m<31)
            {
                if(m<9)
                    cout <<"0"<<m+1;
                else
                    cout <<m+1;
            }
            else if(m<60)
            {
                if(m<40)
                    cout <<"0"<<m-30;
                else
                    cout <<m-30;
            }
            else if(m<91)
            {
                if(m<69)
                    cout <<"0"<<m-59;
                else
                    cout <<m-59;
            }
            else if(m<121)
            {
                if(m<100)
                    cout <<"0"<<m-90;
                else
                    cout <<m-90;
            }
            else if(m<152)
            {
                if(m<130)
                    cout <<"0"<<m-120;
                else
                    cout <<m-120;
            }
            else if(m<182)
            {
                if(m<161)
                    cout <<"0"<<m-151;
                else
                    cout <<m-151;
            }
            else if(m<213)
            {
                if(m<191)
                    cout <<"0"<<m-181;
                else
                    cout <<m-181;
            }
            else if(m<244)
            {
                if(m<222)
                    cout <<"0"<<m-212;
                else
                    cout <<m-212;
            }
            else if(m<274)
            {
                if(m<253)
                    cout <<"0"<<m-243;
                else
                    cout <<m-243;
            }
            else if(m<305)
            {
                if(m<283)
                    cout <<"0"<<m-273;
                else
                    cout <<m-273;
            }
            else if(m<335)
            {
                if(m<314)
                    cout <<"0"<<m-304;
                else
                    cout <<m-304;
            }
            else if(m<366)
            {
                if(m<344)
                    cout <<"0"<<m-334;
                else
                    cout <<m-334;
            }
        }
        else
        {
            if(m<31)
            {
                if(m<9)
                    cout <<"0"<<m+1;
                else
                    cout <<m+1;
            }
            else if(m<59)
            {
                if(m<40)
                    cout <<"0"<<m-30;
                else
                    cout <<m-30;
            }
            else if(m<90)
            {
                if(m<68)
                    cout <<"0"<<m-58;
                else
                    cout <<m-58;
            }
            else if(m<120)
            {
                if(m<99)
                    cout <<"0"<<m-89;
                else
                    cout <<m-89;
            }
            else if(m<151)
            {
                if(m<129)
                    cout <<"0"<<m-119;
                else
                    cout <<m-119;
            }
            else if(m<181)
            {
                if(m<160)
                    cout <<"0"<<m-150;
                else
                    cout <<m-150;
            }
            else if(m<212)
            {
                if(m<190)
                    cout <<"0"<<m-180;
                else
                    cout <<m-180;
            }
            else if(m<243)
            {
                if(m<221)
                    cout <<"0"<<m-211;
                else
                    cout <<m-211;
            }
            else if(m<273)
            {
                if(m<252)
                    cout <<"0"<<m-242;
                else
                    cout <<m-242;
            }
            else if(m<304)
            {
                if(m<282)
                    cout <<"0"<<m-272;
                else
                    cout <<m-272;
            }
            else if(m<334)
            {
                if(m<313)
                    cout <<"0"<<m-303;
                else
                    cout <<m-303;
            }
            else if(m<365)
            {
                if(m<343)
                    cout <<"0"<<m-333;
                else
                    cout <<m-333;
            }
        }
    }
    void week(int n)
    {
        if(n%7==0)
            cout <<"Saturday";
        else if(n%7==1)
            cout <<"Sunday";
        else if(n%7==2)
            cout <<"Monday";
        else if(n%7==3)
            cout <<"Tuesday";
        else if(n%7==4)
            cout <<"Wednesday";
        else if(n%7==5)
            cout <<"Thursday";
        else
            cout <<"Friday";
    }

int main()
{
    int n;
    while(cin >>n)
    {
        if(n==-1)
            break;
        year(n);
        cout <<"-";
        month(n);
        cout <<"-";
        day(n);
        cout <<" ";
        week(n);
        cout <<endl;
    }
    return 0;
}

