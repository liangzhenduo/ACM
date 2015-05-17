#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int t;
    cin >>t;
    for(int i=1;i<=t;i++)
    {
        cin.get();
        char encode[81],mapping[27];
        cin.getline(encode,81);
        cin >>mapping;
        cout <<i<<" ";
        for(int j=0;j<strlen(encode);j++)
        {
            if(encode[j]==' ')
                cout <<" ";
            else
                cout <<mapping[encode[j]-'A'];
        }
        cout <<endl;
    }
    return 0;
}

