#include <iostream>
using namespace std;
int main()
{
    int n;
    do
    {
        cin >>n;
        int total=0;
        const int SIZE=n;
        int speed[SIZE];
        int time[SIZE];
        int distance[SIZE];
        for (int i=0;i<n;i++)
            {
                cin >>speed[i];
                cin >>time[i];
                int t;
                if (i==0)
                    t=time[i];
                else
                    t=time[i]-time[i-1];
                distance[i]=speed[i]*t;
                total =total + distance[i];
            }
        if(total!=0)
            cout <<total<<" miles"<<endl;
    }while (n!=-1);
    return 0;
}
