#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
    char num[32];
    while(cin >>num&&num[0]-48)
    {
        int sum=0;
        for(int i=1;i<=strlen(num);i++)
            sum+=(num[strlen(num)-i]-48)*(pow(2,i)-1);
        cout <<sum<<endl;
    }
    return 0;
}
