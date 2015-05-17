#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int t;
    cin >>t;
    for(int l=0;l<t;l++)
    {
        char url[61];
        int i,j;
        cin >>url;
        cout <<"URL #"<<l+1<<endl;
        for(i=0;i<strlen(url);i++)
            if(url[i]==':')
            {
                cout <<"Protocol = ";
                for(j=0;j<i;j++)
                    cout <<url[j];
                cout <<endl;
                break;
            }
        for(i=j+3;i<strlen(url);i++)
        {
            if(url[i]==':'||url[i]=='/')
            {
                cout <<"Host     = ";
                for(j+=3;j<i;j++)
                    cout <<url[j];
                cout <<endl;
                break;
            }
            else if(i==strlen(url)-1)
            {
                cout <<"Host     = ";
                for(j+=3;j<=i;j++)
                    cout <<url[j];
                cout <<endl;
                break;
            }
        }
        if(url[j]==':')
        {
            cout <<"Port     = ";
            for(j+=1;url[j]!='/'&&j!=strlen(url);j++)
                cout <<url[j];
            cout <<endl;
        }
        else
            cout <<"Port     = <default>"<<endl;
        if(url[j]=='/')
        {
            cout <<"Path     = ";
            for(j+=1;j<strlen(url);j++)
                cout <<url[j];
            cout <<endl;
        }
        else
            cout <<"Path     = <default>"<<endl;
        cout <<endl;
    }
    return 0;
}
