#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char position[11],label[11];
    cin >>position;
    while(cin >>label)
        for(int i=0;i<strlen(position);i++)
            position[i]=(position[i]-48+label[i]-48)%10+48;
    cout <<position<<endl;
    return 0;
}
