#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int m,a,b;
    while(cin >>m>>a>>b&&m)
        cout <<int(sqrt(b)+1)-ceil(sqrt(a))<<endl;
    return 0;
}
