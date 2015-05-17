#include <iostream>
using namespace std;
int main()
{
    int m,n,i,j;
    cin >>m>>n;
    const int x=m+2,y=n,z=x*y;
    char wall[x][y];
    for(i=0;i<x;i++)
        for(j=0;j<y;j++)
            wall[i][j]='1';
    for(i=1;i<=m;i++)
        for(j=0;j<n;j++)
            cin >>wall[i][j];
    int k,l=0,block[z];
    for(j=0;j<n;j++)
        for(i=1;i<=m;i++)
        {
            if(wall[i][j]=='0'&&wall[i-1][j]=='1')
                k=1;
            else if(wall[i][j]=='0'&&wall[i-1][j]=='0')
                k++;
            if(wall[i][j]=='0'&&wall[i+1][j]=='1')
            {
                block[l]=k;
                l++;
            }
        }
    for(i=l-1;i>=1;i--)
    {
        int maximum=block[0],maxI=0;
        for(j=1;j<=i;j++)
        {
            if(maximum<block[j])
            {
                maximum=block[j];
                maxI=j;
            }
        }
        if(maximum!=i)
        {
            block[maxI]=block[i];
            block[i]=maximum;
        }
    }
    j=1;
    for(i=0;i<l;i++)
    {
        int x=block[i];
        if(block[i+1]==block[i])
            j++;
        else
        {
            cout <<x<<" "<<j<<endl;
            j=1;
        }
    }
    return 0;
}

