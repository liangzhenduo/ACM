#include <iostream>
using namespace std;
int main()
{
    int t;
    char time[9];
    cin >>t;
    for(int i=1;i<=t;i++)
    {
        cin >>time;
        int h=10*time[0]+time[1]-528;
        int m=10*time[3]+time[4]-528;
        int s=10*time[6]+time[7]-528;
        int H[6],M[6],S[6];
        for(int j=5;j>=0;j--)
        {
            H[j]=h%2;
            h/=2;
            M[j]=m%2;
            m/=2;
            S[j]=s%2;
            s/=2;
        }
        cout <<i<<" ";
        for(int j=0;j<6;j++)
            cout <<H[j]<<M[j]<<S[j];
        cout <<" ";
        for(int j=0;j<6;j++)
            cout <<H[j];
        for(int j=0;j<6;j++)
            cout <<M[j];
        for(int j=0;j<6;j++)
            cout <<S[j];
        cout <<endl;
    }
    return 0;
}

