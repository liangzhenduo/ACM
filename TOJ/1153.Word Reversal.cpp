#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    cin >>n;
    cin.get();
    const int m=256;
    char text[m];
    for(int g=0;g<n;g++)
    {
        cin.getline(text,m);
        int i=0,blank=0;
        for(int k=0;k<strlen(text);k++)
        {
            int x,y=0;
            for(int k=0;k<strlen(text);k++)
            {
                if(text[k]==' ')
                    y++;
            }

            if(y==0)
            {
                if(k==strlen(text)-1)
                {
                    i=blank;
                    blank=strlen(text);
                    for(x=blank;x>i;x--)
                        cout <<text[x-1];
                }
            }
            else
            {
                if(text[k]==' ')
                {
                    blank=k;
                    for(x=blank;x>i;x--)
                        cout <<text[x-1];
                    i=blank+1;
                    cout <<' ';
                }

                if(k==strlen(text)-1)
                {
                    i=blank;
                    blank=strlen(text);
                    for(x=blank;x>i;x--)
                        if(x!=i+1)
                            cout <<text[x-1];
                }
            }
        }
        cout <<endl;
    }
    return 0;
}

