#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    while(cin >>n&&n)
    {
        char letter[201];
        cin >>letter;
        for(int i=0;i<n;i++)
            for(int j=0;j<strlen(letter)/n;j++)
            {
                if(j%2)
                    cout <<letter[n-1+j*n-i];
                else
                    cout <<letter[j*n+i];
            }
        cout <<endl;
    }
    return 0;
}
