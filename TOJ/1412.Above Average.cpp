#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        int m,k=0;
        cin >>m;
        const int l=m;
        int grade[m];
        for(int j=0;j<m;j++)
        {
            cin >>grade[j];
            k=k+grade[j];
        }
        double average=k/m;
        double above=0;
        for(int j=0;j<m;j++)
            if(grade[j]>average)
                above++;
        double rate=100*above/m;
        cout <<setiosflags(ios::fixed)<<setprecision(3)<<rate<<"%"<<endl;
    }
    return 0;
}

