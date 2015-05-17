#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    int n;
    while(cin >>n&&n)
    {
        int len[101],k=0,flag=0,sho=101;
        char word[101][101];
        for(int i=0;i<n;i++)
        {
            cin >>word[i];
            len[i]=strlen(word[i]);
            if(len[i]<sho)
                sho=len[i];
            reverse(word[i],word[i]+len[i]);
        }
        while(!flag)
        {
            k++;
            if(k==sho)
                break;
            for(int i=0;i<n;i++)
                word[i][--len[i]]='\0';
            for(int i=0;i<n-1&&!flag;i++)
                for(int j=i+1;j<n;j++)
                    if(len[i]==len[j]&&!strcmp(word[i],word[j]))
                    {
                        flag=1;
                        break;
                    }
        }
        cout <<k-1<<endl;
    }
    return 0;
}
