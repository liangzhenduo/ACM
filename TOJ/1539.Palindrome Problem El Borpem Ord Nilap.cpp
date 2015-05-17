#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char text[81];
    while(cin.getline(text,81))
    {
        if(text[0]=='T'&&text[1]=='H'&&text[2]=='E'&&text[3]==' '&&text[4]=='E'&&text[5]=='N'&&text[6]=='D'&&text[7]=='.'&&strlen(text)==8)
            break;
        int k=1;
        for(int i=0,j=strlen(text)-1;i<=j;i++,j--)
        {
            while(!(text[i]>64&&text[i]<91||text[i]>96&&text[i]<123))
                i++;
            while(!(text[j]>64&&text[j]<91||text[j]>96&&text[j]<123))
                j--;
            if(text[i]!=text[j]&&text[i]!=text[j]+32&&text[i]+32!=text[j])
            {
                k=0;
                break;
            }
        }
        if(k)
            cout <<"Yes"<<endl;
        else
            cout <<"No"<<endl;
    }
    return 0;
}

