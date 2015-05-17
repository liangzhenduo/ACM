#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    while(cin >>n&&n)
    {
        int letter[27]={0},bed=0,k=0;
        char cus[53];
        cin >>cus;
        for(int i=0;i<strlen(cus);i++)
        {
            if(!letter[cus[i]-65]&&bed<n)
            {
                letter[cus[i]-65]=1;
                bed++;
            }
            else if(letter[cus[i]-65]==1)
                bed--;
            else if(!letter[cus[i]-65]&&bed==n)
            {
                letter[cus[i]-65]=-1;
                k++;
            }
        }
        if(k)
            cout <<k<<" customer(s) walked away."<<endl;
        else
            cout <<"All customers tanned successfully."<<endl;
    }
    return 0;
}
