#include <iostream>
using namespace std;

    int score(double value[])
    {
        int sum=0;
        for(int i=0;i<6;i+=2)
        {
            double k=value[i]*value[i]+value[i+1]*value[i+1];
            if(k<=9)
                sum+=100;
            else if(k<=36)
                sum+=80;
            else if(k<=81)
                sum+=60;
            else if(k<=144)
                sum+=40;
            else if(k<=225)
                sum+=20;
        }
        return sum;
    }

int main()
{
    double value[12];
    while(cin >>value[0]&&value[0]!=-100)
    {
        for(int i=1;i<12;i++)
            cin >>value[i];
        int a=score(value),b=score(&value[6]);
        cout<<"SCORE: "<<a<<" to "<<b<<", ";
        if(a>b)
            cout <<"PLAYER 1 WINS."<<endl;
        else if(a<b)
            cout <<"PLAYER 2 WINS."<<endl;
        else
            cout <<"TIE."<<endl;
    }
    return 0;
}
