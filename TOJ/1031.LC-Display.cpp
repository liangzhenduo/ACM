#include <iostream>
#include <cstring>
using namespace std;

    void display(int s,char n[],int i,char signs[5][31])
    {
        int m;
        for(int k=0;k<strlen(n);k++)
        {
            m=(n[k]-48)*3;
            cout <<signs[i][m];
            for(int l=0;l<s;l++)
                cout <<signs[i][m+1];
            cout <<signs[i][m+2];
            if(k!=strlen(n)-1)
                cout <<" ";
        }
        cout <<endl;
    }

int main()
{
    char signs[5][31]=
    {
        {" -     -  -     -  -  -  -  - "},
        {"| |  |  |  || ||  |    || || |"},
        {"       -  -  -  -  -     -  - "},
        {"| |  ||    |  |  || |  || |  |"},
        {" -     -  -     -  -     -  - "},
    },n[9];
    int s;
    while(cin >>s>>n&&s+n[0]-48)
    {
        for(int i=0;i<5;i++)
        {
            if(i%2)
                for(int j=0;j<s;j++)
                    display(s,n,i,signs);
            else
                display(s,n,i,signs);
        }
        cout <<endl;
    }
    return 0;
}
