#include <iostream>
using namespace std;
int main()
{
    int m;
    cin >>m;
    for(int i=0;i<m;i++)
    {
        double length;
        cin >>length;
        int distanceMAX,distanceMIN,roadMAX=0,roadMIN=0;
        int n;
        cin >>n;
        for(int j=0;j<n;j++)
        {
            int position;
            cin >>position;
            if(position<=length/2)
            {
                distanceMAX=length-position;
                distanceMIN=position;
            }
            else
            {
                distanceMAX=position;
                distanceMIN=length-position;
            }

            if(distanceMAX>=roadMAX)
                roadMAX=distanceMAX;

            if(distanceMIN>=roadMIN)
                roadMIN=distanceMIN;
        }
        cout <<roadMIN<<" "<<roadMAX<<endl;
    }
    return 0;
}

