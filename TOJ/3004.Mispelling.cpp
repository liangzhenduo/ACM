#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int t,n;
    char word[81];
    cin >>t;
    for(int i=1;i<=t;i++)
    {
        cin >>n>>word;
        for(int j=n-1;j<strlen(word)-1;j++)
            word[j]=word[j+1];
        cout <<i<<" ";
        for(int j=0;j<strlen(word)-1;j++)
            cout <<word[j];
        cout <<endl;
    }
    return 0;
}

