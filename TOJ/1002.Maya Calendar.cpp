#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int day=0,month=0,year=0,days=0;
    int T,D,Y;
    string haabDay,haabMonth,tzolkinDay;
    int n;
    cin >>n;
    cout <<n<<endl;
    for(int i=0;i<n;i++)
    {
        cin >>haabDay;
        if(haabDay=="0.")
            day=0;
        else if(haabDay=="1.")
            day=1;
        else if(haabDay=="2.")
            day=2;
        else if(haabDay=="3.")
            day=3;
        else if(haabDay=="4.")
            day=4;
        else if(haabDay=="5.")
            day=5;
        else if(haabDay=="6.")
            day=6;
        else if(haabDay=="7.")
            day=7;
        else if(haabDay=="8.")
            day=8;
        else if(haabDay=="9.")
            day=9;
        else if(haabDay=="10.")
            day=10;
        else if(haabDay=="11.")
            day=11;
        else if(haabDay=="12.")
            day=12;
        else if(haabDay=="13.")
            day=13;
        else if(haabDay=="14.")
            day=14;
        else if(haabDay=="15.")
            day=15;
        else if(haabDay=="16.")
            day=16;
        else if(haabDay=="17.")
            day=17;
        else if(haabDay=="18.")
            day=18;
        else if(haabDay=="19.")
            day=19;

        cin >>haabMonth;
        if(haabMonth=="pop")
            month=0;
        else if(haabMonth=="no")
            month=20;
        else if(haabMonth=="zip")
            month=40;
        else if(haabMonth=="zotz")
            month=60;
        else if(haabMonth=="tzec")
            month=80;
        else if(haabMonth=="xul")
            month=100;
        else if(haabMonth=="yoxkin")
            month=120;
        else if(haabMonth=="mol")
            month=140;
        else if(haabMonth=="chen")
            month=160;
        else if(haabMonth=="yax")
            month=180;
        else if(haabMonth=="zac")
            month=200;
        else if(haabMonth=="ceh")
            month=220;
        else if(haabMonth=="mac")
            month=240;
        else if(haabMonth=="kankin")
            month=260;
        else if(haabMonth=="muan")
            month=280;
        else if(haabMonth=="pax")
            month=300;
        else if(haabMonth=="koyab")
            month=320;
        else if(haabMonth=="cumhu")
            month=340;
        else if(haabMonth=="uayet")
            month=360;

        cin >>year;
        days=365*year+month+day;
        Y=days/260;
        T=days%13+1;
        D=(days%260)%20;

        if(D==0)
            tzolkinDay="imix";
        else if(D==1)
            tzolkinDay="ik";
        else if(D==2)
            tzolkinDay="akbal";
        else if(D==3)
            tzolkinDay="kan";
        else if(D==4)
            tzolkinDay="chicchan";
        else if(D==5)
            tzolkinDay="cimi";
        else if(D==6)
            tzolkinDay="manik";
        else if(D==7)
            tzolkinDay="lamat";
        else if(D==8)
            tzolkinDay="muluk";
        else if(D==9)
            tzolkinDay="ok";
        else if(D==10)
            tzolkinDay="chuen";
        else if(D==11)
            tzolkinDay="eb";
        else if(D==12)
            tzolkinDay="ben";
        else if(D==13)
            tzolkinDay="ix";
        else if(D==14)
            tzolkinDay="mem";
        else if(D==15)
            tzolkinDay="cib";
        else if(D==16)
            tzolkinDay="caban";
        else if(D==17)
            tzolkinDay="eznab";
        else if(D==18)
            tzolkinDay="canac";
        else if(D==19)
            tzolkinDay="ahau";

        cout <<T<<" "<<tzolkinDay<<" "<<Y<<endl;
    }
    return 0;
}

