#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    cout <<"n e"<<endl<<"- -----------"<<endl<<"0 1"<<endl<<"1 2"<<endl<<"2 2.5"<<endl;
    double e=2.5;
    for(int i=3;i<10;i++)
    {
        double k=1;
        for(int j=i;j>0;j--)
            k*=j;
        e+=1/k;
        cout <<setiosflags(ios::fixed)<<setprecision(9)<<i<<" "<<e<<endl;
    }
    return 0;
}

