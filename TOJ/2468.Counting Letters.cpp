#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    cin >>n;
    for(int k=0;k<n;k++)
    {
        char letter[101];
        cin >>letter;
        for(int i=strlen(letter)-1;i>=1;i--)
        {
            int maximum=letter[0],maxI=0;
            for(int j=1;j<=i;j++)
                if(maximum<letter[j])
                {
                    maximum=letter[j];
                    maxI=j;
                }
            if(maxI!=i)
            {
                letter[maxI]=letter[i];
                letter[i]=maximum;
            }
        }
        int t=1,s=0;
        char frequent[101]={'\0'};
        for(int i=0;i<strlen(letter);i++)
        {
            if(letter[i]==letter[i+1])
                t++;
            else
            {
                if(t>s)
                {
                    frequent[0]=letter[i];
                    for(int j=1;j<101;j++)
                        frequent[j]='\0';
                }
                else if(t==s)
                    frequent[strlen(frequent)]=letter[i];
                if(t>s)
                    s=t;
                t=1;
            }
        }
        cout <<frequent<<endl;
    }
    return 0;
}

