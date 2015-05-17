#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char word[1000001];
    int n;
    cin >>n;
    while(n--)
    {
        cin >>word;
        int k=0,n=0;
        for(int i=0;i<strlen(word);i++)
        {
            if(word[i]=='U')
                n+=3;
            else if(word[i]=='M')
                k++;
            else if(word[i]=='I')
                n++;
        }
        cout <<(word[0]=='M'&&k==1&&(n%2==0&&n%3||n==1)?"Yes":"No")<<endl;
    }
    return 0;
}
