#include <iostream>
#include <cmath>
using namespace std;

    int hanoi(int n)
    {
         int k=pow(2,n)-1;
         for(int i=1;i<n;i++)
            k=(k>2*hanoi(n-i)+pow(2,i)-1?2*hanoi(n-i)+pow(2,i)-1:k);
         return k;
    }

int main()
{
     int n=0;
     while(++n&&n-13)
        cout <<hanoi(n)<<endl;
     return 0;
}
