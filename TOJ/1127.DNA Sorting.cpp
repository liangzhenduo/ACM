#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin >>n>>m;
    const int p=m,q=n;
    char dna[p][q+1];
    int measure[p],maximum=0;
    for(int i=0;i<m;i++)
    {
        cin >>dna[i];
        int k=0,j;
        for(j=0;j<n-1;j++)
            for(int l=j+1;l<n;l++)
                if(dna[i][j]>dna[i][l])
                    k++;
        measure[i]=k;
        if(maximum<k)
            maximum=k;
    }
    for(int l=0;l<m;l++)
        for(int i=0;i<m;i++)
        {
            int o=1;
            for(int j=0;j<m;j++)
            {
                if(measure[i]>measure[j])
                {
                    o=0;
                    break;
                }
            }
            if(o==1)
            {
                for(int k=0;k<n;k++)
                    cout <<dna[i][k];
                cout <<endl;
                measure[i]=maximum+1;
                break;
            }
        }
    return 0;
}

