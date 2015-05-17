#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        char word[41];
        cin >>word;
        if(word[0]=='a'||word[0]=='e'||word[0]=='i'||word[0]=='o'||word[0]=='u')
            cout <<word<<"cow"<<endl;
        else
        {
            for(int j=1;j<strlen(word);j++)
                cout <<word[j];
            cout <<word[0]<<"ow"<<endl;
        }
    }
    return 0;
}
