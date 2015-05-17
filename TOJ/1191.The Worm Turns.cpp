#include <iostream>
using namespace std;
int main()
{
    int n;
    int x[20],y[20];
    while(cin >>n&&n!=0)
    {
        const int m=n+1;
        char direction[m];
        for(int i=0;i<n;i++)
            cin >>direction[i];
        for(int i=0;i<20;i++)
        {
            x[i]=25;
            y[i]=30-i;
        }
        int i,k=0;
        for(i=0;i<n;i++)
        {
            for(int j=0;j<19;j++)
            {
                x[19-j]=x[18-j];
                y[19-j]=y[18-j];
            }
            if(direction[i]=='E')
                y[0]++;
            else if(direction[i]=='W')
                y[0]--;
            else if(direction[i]=='S')
                x[0]++;
            else if(direction[i]=='N')
                x[0]--;

            if(x[0]>50||x[0]<1||y[0]>50||y[0]<1)
            {
                k=1;
                break;
            }
            for(int j=1;j<20;j++)
                if(x[0]==x[j]&&y[0]==y[j])
                {
                    k=-1;
                    break;
                }
            if(k==-1)
                break;
        }
        if(k==0)
            cout <<"The worm successfully made all "<<n<<" moves."<<endl;
        else if(k==-1)
            cout <<"The worm ran into itself on move "<<i+1<<"."<<endl;
        else if(k==1)
            cout <<"The worm ran off the board on move "<<i+1<<"."<<endl;
    }
    return 0;
}
