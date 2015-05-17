#include <iostream>
using namespace std;
int main()
{
    const double PI=3.14159;
    int n;
    cin >>n;
    for (int i=0;i<n;i++)
    {
        double x,y,z=0;
        double area = 0;
        cin >>x;
        cin >>y;
        double distance=x*x+y*y;
        do
        {
            z++;
            area=100*z;
            if(area/PI>distance)
                cout <<"Property "<<i+1<<": This property will begin eroding in year "<<z<<"."<<endl;
        }while (area/PI<=distance);

    }
    cout <<"END OF OUTPUT."<<endl;
    return 0;
}

