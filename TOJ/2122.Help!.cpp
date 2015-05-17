#include <iostream>
using namespace std;
int main()
{
    int n,t;
    string judgement;
    char identifier;
    while(cin >>n&&n)
    {
        int s=0,p=0,k[26]={0};
        while(n--)
        {
            cin >>identifier>>t>>judgement;
            if(judgement=="incorrect")
                k[identifier-65]++;
            if(judgement=="correct")
            {
                s++;
                p+=t;
                if(k[identifier-65])
                    p+=k[identifier-65]*20;
            }
        }
        cout <<s<<" "<<p<<endl;
    }
    return 0;
}
