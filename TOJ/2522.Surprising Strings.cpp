#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char letters[80];
    while(cin >>letters&&letters[0]!='*')
    {
        int l=strlen(letters),k=0;
        for(int i=1;i<l;i++)
        {
            for(int j=0;j<l;j++)
            {
                for(int h=j+1;h+i<l;h++)
                    if(letters[j]==letters[h]&&letters[j+i]==letters[h+i])
                    {
                        k++;
                        break;
                    }
                if(k==1)
                    break;
            }
            if(k==1)
                break;
        }
        cout <<letters<<" is";
        if(k)
            cout <<" NOT";
        cout <<" surprising."<<endl;
        memset(letters,0,sizeof(letters));
    }
    return 0;
}
