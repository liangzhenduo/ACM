#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    cin >>n;
    for(int k=0;k<n;k++)
    {
        char word1[51],word2[51];
        cin >>word1>>word2;
        for(int j=0;j<strlen(word1);j++)
            for(int i=0;i<strlen(word2);i++)
                if(word1[j]==word2[i]||word1[j]==word2[i]+32||word1[j]==word2[i]-32)
                {
                    word1[j]='=';
                    word2[i]='=';
                    break;
                }
        int WORD1=1,WORD2=1;
        for(int j=0;j<strlen(word1);j++)
            if(word1[j]!='=')
            {
                WORD1=0;
                break;
            }
        for(int i=0;i<strlen(word2);i++)
            if(word1[i]!='=')
            {
                WORD2=0;
                break;
            }
        if(WORD1==1&&WORD2==1)
            cout <<"Yes"<<endl;
        else
            cout <<"No"<<endl;
    }
    return 0;
}

