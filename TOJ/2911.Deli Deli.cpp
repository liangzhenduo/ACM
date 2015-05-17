#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int l,n;
    char irregular[20][2][21],word[21];
    cin >>l>>n;
    for(int i=0;i<l;i++)
        cin >>irregular[i][1]>>irregular[i][2];
    for(int i=0;i<n;i++)
    {
        cin >>word;
        int k=1,len=strlen(word);
        for(int j=0;j<l;j++)
            if(!strcmp(word,irregular[j][1]))
            {
                cout <<irregular[j][2]<<endl;
                k=0;
                break;
            }
        if(k)
        {
            if(word[len-1]=='y'&&word[len-2]!='a'&&word[len - 2]!='e'&&word[len-2]!='i'&&word[len-2]!='o'&&word[len-2]!='u')
            {
                for(int j=0;j<len-1;j++)
                    cout <<word[j];
                cout <<"ies"<<endl;
            }
            else if(word[len-1]=='o'||word[len-1]=='s'||word[len-1]=='x'||(word[len-1]=='h'&&(word[len-2]=='c'||word[len-2]=='s')))
            {
                for(int j=0;j<len;j++)
                    cout <<word[j];
                cout <<"es"<<endl;
            }
            else
            {
                for(int j=0;j<len;j++)
                    cout <<word[j];
                cout <<"s"<<endl;
            }
        }
    }
    return 0;
}
