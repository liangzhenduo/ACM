#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin >>n&&n!=0)
    {
        const int m=n;
        int matrix[m][m],i,j;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin >>matrix[i][j];
        int sumRow[m],sumColumn[m];
        for(i=0;i<n;i++)
        {
            sumRow[i]=0;
            for(j=0;j<n;j++)
                sumRow[i]+=matrix[i][j];
        }
        for(j=0;j<n;j++)
        {
            sumColumn[j]=0;
            for(i=0;i<n;i++)
                sumColumn[j]+=matrix[i][j];
        }
        int p=0,q=0,x,y;
        for(i=0;i<n;i++)
        {
            if(sumRow[i]%2==1)
            {
                p++;
                x=i+1;
            }
            if(sumColumn[i]%2==1)
            {
                q++;
                y=i+1;
            }
        }
        if(p==0&&q==0)
            cout <<"OK"<<endl;
        else if(p==1&&q==1)
            cout <<"Change bit ("<<x<<","<<y<<")"<<endl;
        else
            cout <<"Corrupt"<<endl;
    }
    return 0;
}

