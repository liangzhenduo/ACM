#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >>n;
    for(int l=1;l<=n;l++)
    {
        int m,k=0;
        cin >>m;
        const int o=m;
        int num[o];
        for(int j=0;j<m;j++)
            cin >>num[j];
        for(int i=0;i<m;i++)
        {
            int number=num[i],index=i;
            for(int j=i;j<m;j++)
                if(number>num[j])
                {
                    number=num[j];
                    index=j;
                }
            for(int j=index-1;j>=0;j--)
                num[j+1]=num[j];
            num[i]=number;
            k=k+index-i;
        }
        cout <<"Scenario #"<<l<<":"<<endl;
        cout <<k<<endl<<endl;
    }
    return 0;
}

