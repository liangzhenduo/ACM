#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char word[256];
    int t=0;
    while(cin >>word)
        for(int i=0;i<strlen(word);i++)
            if(!(word[i-1]>47&&word[i-1]<58||word[i-1]>64&&word[i-1]<91||word[i-1]>96&&word[i-1]<123)&&(word[i]>47&&word[i]<58||word[i]>64&&word[i]<91||word[i]>96&&word[i]<123))
                t++;
    cout <<t<<endl;
    return 0;
}
