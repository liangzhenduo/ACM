#include <iostream>
using namespace std;
int main()
{
    int quarter,dime,nickel,penny,cent;
    while(cin >>quarter>>dime>>nickel>>penny>>cent)
    {
        if(quarter==0&&dime==0&&nickel==0&&penny==0&&cent==0)
            break;
        int c,q,d,n,p,Q=quarter,D=dime,N=nickel,P=penny;
        for(quarter=quarter;quarter>=0;quarter--)
        {
            c=cent;
            for(q=0;q<quarter;q++)
            {
                if(c<25)
                    break;
                c=c-25;
            }
            for(d=0;d<dime;d++)
            {
                if(c<10)
                    break;
                c=c-10;
            }
            for(n=0;n<nickel;n++)
            {
                if(c<5)
                    break;
                c=c-5;
            }
            for(p=0;p<penny;p++)
            {
                if(c<1)
                    break;
                c=c-1;
            }
            if(q+d+n+p<=Q+D+N+P&&c==0)
            {
                Q=q;
                D=d;
                N=n;
                P=p;
            }
        }
        if(25*Q+10*D+5*N+P==cent)
            cout <<"Dispense "<<Q<<" quarters, "<<D<<" dimes, "<<N<<" nickels, and "<<P<<" pennies."<<endl;
        else
            cout <<"Cannot dispense the desired amount."<<endl;
    }
    return 0;
}

