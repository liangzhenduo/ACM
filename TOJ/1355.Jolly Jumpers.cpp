#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin >>n)
    {
        const int m=n;
        int sequence[m];
        for(int i=0;i<n;i++)
            cin >>sequence[i];
        int difference[m-1];
        for(int i=0;i<n-1;i++)
        {
            if(sequence[i+1]>sequence[i])
                difference[i]=sequence[i+1]-sequence[i];
            else
                difference[i]=sequence[i]-sequence[i+1];
        }
        int k;
        for(int i=1;i<n;i++)
        {
            k=0;
            for(int j=0;j<n-1;j++)
                if(difference[j]==i)
                {
                    k=1;
                    break;
                }
            if(k==0)
            {
                cout <<"Not jolly"<<endl;
                break;
            }
        }
        if(k==1||n==1)
            cout <<"Jolly"<<endl;
    }
    return 0;
}

