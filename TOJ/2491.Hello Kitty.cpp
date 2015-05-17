#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char word[256];
    while(cin >>word&&word[0]!='.')
    {
        int n;
        cin >>n;
        const int l=n*strlen(word);
        char words[l];
        for(int i=0;i<l;i++)
            words[i]=word[i%strlen(word)];
        for(int i=0;i<strlen(word);i++)
        {
            for(int j=0;j<l;j++)
                cout <<words[j];
            char letter=words[0];
            cout <<endl;
            for(int j=0;j<l-1;j++)
                words[j]=words[j+1];
            words[l-1]=letter;
        }
    }
    return 0;
}
